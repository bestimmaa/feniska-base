# Feniska

Reviving two **Feniska** smart cat-toilet scale bases after the company behind them (a Berlin pet-tech startup) shut down. The original firmware only talked to Feniska's AWS cloud, so the bases went dead with it. This project reflashes them with [ESPHome](https://esphome.io) so they become local weight sensors for Home Assistant, with no cloud involved.

**Project hub (Notion):** https://app.notion.com/p/3f4c5d5fe196816b83dfd5d20fb827d6. It has the plan, device facts and current status.

## Status

| | Base #1 | Base #2 |
|---|---|---|
| Firmware backup | ✅ verified (2× identical dumps) | — |
| ESPHome | ✅ flashed over USB, calibrated | ⏳ not started |
| Home Assistant | ⏳ | ⏳ |

Cat-visit detection is still to do. The original device only sent raw weights; recognising visits happened in Feniska's cloud.

## Hardware

- **Controller:** LILYGO TTGO T-Display V1.1 (ESP32-D0WDQ6-V3, 4 MB flash, ST7789 135×240 display), with built-in USB-C serial
- **Scale:** four 3-wire load cells feeding an HX711 board
- **Pins** (read from the original firmware, see [`re/FINDINGS.md`](re/FINDINGS.md)):

| Function | GPIO |
|---|---|
| HX711 DOUT / SCK | 15 / 2 (both strapping pins) |
| TFT CS / DC / RST / backlight | 5 / 16 / 23 / 4 (PWM) |
| Button | 35 |

## Repository layout

```
AGENTS.md                      instructions for AI agents (start at the Notion hub)
re/
  feniska-base.esphome.yaml    ESPHome config for the bases
  FINDINGS.md                  reverse-engineering results for the original firmware v16
  esp2elf.py                   wraps an ESP32 app image into an ELF for Ghidra
  scripts/                     Ghidra headless scripts + helpers
  out/, out2/                  decompiled functions / disassembly used as evidence
dumps/                         original flash dumps (git-ignored)
```

## Usage

The steps below assume [uv](https://docs.astral.sh/uv/) is installed. ESPHome runs through `uvx`, so nothing gets installed globally.

### Secrets

Create `re/secrets.yaml` (it's git-ignored):

```yaml
wifi_ssid: "..."
wifi_password: "..."
feniska_api_key: "..."        # 32 random bytes, base64: openssl rand -base64 32
feniska_ota_password: "..."
feniska_ap_password: "..."    # fallback hotspot, min. 8 chars
```

### Build and flash

```bash
cd re
uvx esphome compile feniska-base.esphome.yaml
uvx esphome upload feniska-base.esphome.yaml --device /dev/cu.usbserial-XXXX   # USB
uvx esphome upload feniska-base.esphome.yaml --device feniska-base.local       # OTA, once ESPHome runs
uvx esphome logs feniska-base.esphome.yaml --device /dev/cu.usbserial-XXXX
```

Both bases currently share the device name `feniska-base`. Give base #2 its own `name` substitution before flashing it.

### Tare and read

At boot the scale zeroes on whatever is on it, the same as the original firmware. Tare again if it restarted with something on it:

```bash
curl -X POST -d '' http://feniska-base.local/button/Tare/press
curl -s http://feniska-base.local/sensor/Weight%20%28live%29
```

Entity names in these URLs are case-sensitive, and the POST needs a body. You can also open `http://feniska-base.local` in a browser.

### Calibration

`calib_fac` in the YAML is the number of raw counts per gram. To recalibrate, read the raw HX711 values (`uvx esphome logs …`) with the base empty and again with a known weight on it, then use:

```
calib_fac = (raw_loaded − raw_empty) / reference_grams
```

Base #1 measured **24.1221** with a 1320.7 g reference. The factory value from NVS was 23.7618. Readings vary by about 2–3 % depending on where the load sits on the four corner cells.

## Flashing a base that still runs the original firmware

- **Over USB (recommended):** connect a USB-C *data* cable to the T-Display. Back up first:
  ```bash
  python -m esptool --port PORT read-flash 0 ALL dumps/feniska-baseN-original.bin
  ```
  Then flash with `esphome upload` as above.
- **Over Wi-Fi without opening the case:** the original firmware installs any image it's pointed at, with no signature check:
  ```
  GET http://<base-ip>/update?deviceuuid=<devUuid>&url=http://<host>/firmware.ota.bin
  ```
  The server must use plain http and send `Content-Type: application/octet-stream` and a `Content-Length`. The image must be smaller than 1,310,720 bytes; ESPHome's `firmware.ota.bin` is about 0.95 MB. You need the base's own `devUuid`, which is stored only in that base's NVS. Details are in [`re/FINDINGS.md`](re/FINDINGS.md) §5.

## Restoring the original firmware

```bash
python -m esptool --port PORT write-flash 0 dumps/feniska-base1-original-1.bin
```

The dump includes NVS: device UUID, calibration and Wi-Fi. Its SHA-256 is `941e94b11eeadd270f0ebcaf4497229dd3f32446c45b19dcdca443ba97a17489`.

## Reverse engineering

The original firmware (Arduino-ESP32, PlatformIO, July 2022) was decompiled with Ghidra 12 (Xtensa). To reproduce:

```bash
brew install ghidra
python re/esp2elf.py dumps/app0.bin re/app0.elf
export JAVA_HOME=$(brew --prefix openjdk@21)/libexec/openjdk.jdk/Contents/Home
$(brew --prefix ghidra)/libexec/support/analyzeHeadless re/proj feniska \
  -import re/app0.elf -processor "Xtensa:LE:32:default" \
  -scriptPath "$PWD/re/scripts" -postScript DumpByStrings.java "$PWD/re/out" "init and start HX711 scale"
```

`dumps/app0.bin` is the `app0` partition: offset `0x10000`, size `0x140000`. Results, including the function map, measurement logic, MQTT protocol and HTTP routes, are in [`re/FINDINGS.md`](re/FINDINGS.md).
