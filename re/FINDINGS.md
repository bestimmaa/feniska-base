# Feniska Base firmware (v16, Jul 4 2022) — RE findings

CONFIRMED = seen in code; INFERRED = deduced. Decompiles: `out/`, `out2/`. Scripts: `scripts/` (`DumpByStrings.java`, `DecompAt.java`, `Disasm.java`, `CallArgs.java`, `peek.py`, `run.sh`).

**Libraries:** HX711 = Rob Tillaart's library (`float read()`, mode byte +0x14 with 2 = MEDAVG, `set_scale` stores 1/s, `tare` sets `_offset = read_average(n)`). Web server = synchronous Arduino `WebServer` on :80, shared with IotWebConf.

## Function map

| Address | Role |
|---|---|
| 0x400d7140 | setup |
| 0x400d7950 | loop |
| 0x400d75d4 | static constructors |
| 0x400d5190 | measureAndDisplayTask |
| 0x400d50c0 | shouldSend |
| 0x400d4ea4 | display clamp |
| 0x400d5ac4 | weightToRaw |
| 0x400d4ef8 | sendMeasurementsTask |
| 0x400d4930 | publish /weight |
| 0x400d476c | publish /firmwareversion |
| 0x400d4b74 | publish /meta |
| 0x400d46ac | _sendDataToMQTTServer |
| 0x400d4500 | MQTT connect + subscribe |
| 0x400d7704 | MQTT onMessage |
| 0x400d61e0 | HTTP routes |
| 0x400d58b4 | uuid check |
| 0x400d64b0 | handleOTA |
| 0x400d664c / 0x400dca50 | esp32FOTA / execOTA |
| 0x400d5300 | NVS reset (keeps calibration + IDs) |
| 0x400d5510 | button handler |
| 0x400d7e14 / 7dc4 / 7e80 / 7f0c / 7fc4 / 80b4 / 810c | HX711 begin / reset / read / read_average / read_medavg / get_value / get_units |
| 0x400d34e8 | showWeight |
| 0x400d3834 | status line |

## 1. HX711

- **DOUT = GPIO15, SCK = GPIO2 (CONFIRMED).** At 0x400d7401: `movi.n a12,0x2; movi.n a11,0xf; call8 HX711::begin`. `begin` does `pinMode(15, INPUT); pinMode(2, OUTPUT); digitalWrite(2, LOW)`; `read()` waits on `digitalRead(15)`. Contradicts the earlier GPIO32/33 wiring guess.
- **Gain 128, channel A (CONFIRMED):** `reset()` sets gain = 0x80, never changed; `read()` sends 1 extra clock pulse.
- **Averaging (CONFIRMED):** mode 2 (MEDAVG) + `get_units(10)` → 10 reads, sorted, drop 3 at each end, average the middle 4.
- **Interval:** `vTaskDelay(50)` + 10 conversions ≈ 1.05 s at 10 SPS (≈ 0.18 s at 80 SPS; RATE pin is hardware — INFERRED).

## 2. measureAndDisplayTask (CONFIRMED)

Each loop:
1. **Uplink check:** if the oldest queued reading is > 120 s old → new TLS client, reconnect MQTT.
2. **Measure:** `w = get_units(10) / 1000` (kg).
3. **Zero tracking:** if |w| < 0.01 kg → offset = current raw.
4. **Queue:** if `shouldSend(|w − lastSent|, ms since last send)` → queue `{epoch, w, raw}` with `raw = offset + w·1000·calibFac` (blocks if full).
5. **Display:** clamp w to 0 if in (−0.05, 0.05) or negative; redraw only if it moved > 0.05 kg.

`shouldSend` (0x400d50c0; branch order checked in `out2/decide.asm`):
- queue (len 360) has no free space → 0
- queue > 80 % full and > 300 s passed → 1
- dw > 0.02 kg → state = 0, return 1
- state 0 and dt > 10 s → state = 1, return 1
- state 1/2 and dt > 180 s → state = 2, return 1

→ Send on > 20 g change, once more 10 s after settling, then every 3 min. **No cat-visit detection on the device** (was done in the cloud).

**Display** (rotation 1, 240×135):
- weight ≥ 0.1 kg: `setTextSize(3); drawFloat(kg, 2, 15, 50)`, `"kg"` at (130, 60) font 2
- else: `"BASE ID: "+devId` at (15, 50), `"WiFi: "+SSID` at (15, 90)
- status line: `fillRect(0,120,240,15)` + `drawCentreString(msg, 120, 120, 2)`

## 3. sendMeasurementsTask & MQTT (CONFIRMED)

- Polls the queue every 200 ms, one item per publish; no batching.
- Publish retry: up to 10 tries, 4000 ms apart; then retries the same item every 500 ms forever.
- `connect()` retries every 5 s (recursively).
- Broker `aunev1aoh3apb-ats.iot.eu-central-1.amazonaws.com:8883`, TLS, QoS 0, retain false.
- `base/data/<devId>/weight`: `{"devUuid":"..","logdate":"YYYY-MM-DD HH:MM:SS","weight":"1.23","rawValue":"430000.00"}` — string values, 2 decimals, kg, UTC (NTP pool.ntp.org).
- `base/data/<devId>/firmwareversion`: `{"deviceId":"<uuid>","logdate":"..","version":"16"}`
- `base/data/<devId>/meta`: `{"logtime","deviceUuid","rssi","firmware":16,"ip","calibFac"}` — both sent once on coming online.
- Subscribes to `base/action/<devUuid>`. `devId` / `devUuid` are NVS keys in namespace `feniska`.
- **Startup gating (INFERRED):** both tasks start suspended and resume only once IotWebConf is OnLine and MQTT connect succeeds → without AWS the device never measures.

## 4. Calibration (CONFIRMED)

- Setup: `offset = calibOff`, `scale = 1/calibFac` → kg = (raw − offset) / calibFac / 1000 (positive sign).
- Boot tare: "Zeroing the base", `delay(300)`, `offset = read_average(10)` — overwrites calibOff in RAM every boot.
- `/tare` and MQTT `tare`: same, RAM only.
- Only NVS writes of calibFac/calibOff are in 0x400d5300, which writes back the values just read. **The per-unit factory calibFac (typically ~24 counts/g) is the calibration that matters.**

## 5. HTTP & MQTT actions (CONFIRMED)

Routes via `server.on()` (any method). uuid param = **`deviceuuid`**; wrong → `400 "device uuid is wrong."`

| Route | Behaviour |
|---|---|
| `/update?deviceuuid=U&url=URL` | 200 "update starting", then esp32FOTA downloads URL |
| `/tare?deviceuuid=U` | RAM tare, 200 "ok" |
| `/reset?deviceuuid=U` | NVS reset (keeps calibration + IDs), restart |
| `/dim?deviceuuid=U&brightness=0..255` | backlight PWM, 200 "ok" |
| `/portal`, `/setwifi?ssid=&password=`, `/networks`, `/hellofeniska`, `/close`, `/continue`, `/` | IotWebConf provisioning, no uuid check |

**esp32FOTA:** `("esp32-fota-http", 16, validate=false, allow_insecure=false)`, `forceUpdate(url, false)`, 5 attempts.
- Use **http** (https needs `/root_ca.pem` in SPIFFS).
- Server must answer 200/301 with Content-Length > 0 and `Content-Type: application/octet-stream` (exact match).
- Written via `Update`, then restart. **No signature or MD5 check → an unsigned ESPHome `firmware.ota.bin` can be OTA'd.**
- otadata boots app0 → update lands in app1; image must be < 1,310,720 bytes.
- Timing caveat (INFERRED): `loop()` may block in the recursive MQTT connect once online — send the request soon after boot; keep USB as fallback.

**MQTT actions** on `base/action/<devUuid>`: `reset`, `tare`, `dim:N`, `message:<text>` (shown on display), `forceupdate:<url>` (same OTA path, no uuid check).

## 6. Display & buttons (CONFIRMED)

- TFT: CS 5, DC 16, RST 23, BL 4 (SPI 18/19 = standard T-Display, INFERRED).
- Backlight: `ledcSetup(1, 12000, 8); ledcAttachPin(4, 1); ledcWrite(1, 255)`; changes only via `/dim` / MQTT `dim:`.
- Button: GPIO35 only, 20 ms debounce. Single press logged only; double click (300 ms) → display demo; 5 s press → Wi-Fi wipe via NVS reset + restart.
- GPIO0 and IotWebConf status/config pins unused.

## 7. Other

- No deep sleep, no extra LEDs/sensors, no custom watchdog.
- Tasks: 8000-byte stacks, priority 0, core 0. Queue: 360 × 12 bytes.
- mDNS `feniska-<devId>`; AP name `FENISKA-BASE`.
- GPIO2 and GPIO15 are strapping pins → ESPHome needs `ignore_strapping_warning: true`.
