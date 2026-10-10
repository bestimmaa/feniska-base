# Feniska Base → ESPHome

Revives the **Feniska** smart cat-toilet scale base after the Berlin pet-tech startup behind it shut down. The original firmware only talked to Feniska's AWS cloud, so the bases stopped working when the cloud did. This project reflashes them with [ESPHome](https://esphome.io) so they become local weight sensors for Home Assistant, with no cloud involved.

## What you get

- Weight in kg, using the original firmware's filtering and sending rules (more than 20 g change, then once 10 s later, then every 3 min), plus a live value about once per second
- The weight shown on the built-in display, as before
- Tare, restart and backlight controls in Home Assistant and through a local web API
- The original calibration math, with a simple procedure to recalibrate

- Basic visit detection on the device (the original left this to Feniska's cloud). Anything heavier than `visit_min_kg` (default 1 kg) for at least 5 s counts as a visit. A visit ends only after `visit_end_samples` (default 10, about 10 s) below the threshold, so a cat stepping half out and back in stays one visit. The weight is measured against the lowest reading of the ~30 s before the visit, so a paw resting on the box before the jump doesn't make the cat read light. If all your cats are well above 1 kg, raise `visit_min_kg` (e.g. to 2.0) in your local override so a cat with only its front paws on the rim doesn't count. The base reports **Last Visit Weight** (median weight during the visit, i.e. the cat), **Peak**, **Duration**, **Residue** (weight left behind, measured 20 s after the cat leaves), **Last Visit Time** and **Visits Since Boot**. It also reports **Uptime**, so a restart, which re-tares the scale, can be spotted.

```bash
curl -s http://feniska-base.local/sensor/Last%20Visit%20Weight
curl -s http://feniska-base.local/text_sensor/Last%20Visit%20Time
```

- Optional [Home Assistant setup](#home-assistant-cat-identification) that tells cats apart by weight, tracks each cat's weight over time and adds a "Cats" dashboard.

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
re/
  feniska-base.esphome.yaml    ESPHome config
  FINDINGS.md                  reverse-engineering results for the original firmware v16
  esp2elf.py                   wraps an ESP32 app image into an ELF for Ghidra
  scripts/                     Ghidra headless scripts + helpers
  out/, out2/                  decompiled functions / disassembly used as evidence
homeassistant/
  setup_ha.py                  creates cat identification + "Cats" dashboard via the HA API
  cats.example.toml            config template (copy to cats.local.toml)
  recent.py, set_weights.py    show recent activity / set reference weights
```

## Usage

The steps below assume [uv](https://docs.astral.sh/uv/) is installed. ESPHome runs through `uvx`, so nothing gets installed globally.

### 1. Back up the original firmware

Open the base and connect the T-Display with a USB-C **data** cable. Then make a full flash dump; it can be written back later.

```bash
uvx --from esptool esptool --port /dev/cu.usbserial-XXXX read-flash 0 ALL feniska-original.bin
```

Make a second dump and compare the hashes before going further. The dump contains the base's stored data (NVS): device UUID, factory calibration and Wi-Fi credentials. Keep it private.

### 2. Secrets

Create `re/secrets.yaml` (it's git-ignored):

```yaml
wifi_ssid: "..."
wifi_password: "..."
feniska_api_key: "..."        # 32 random bytes, base64: openssl rand -base64 32
feniska_ota_password: "..."
feniska_ap_password: "..."    # fallback hotspot, min. 8 chars
```

### 3. Build and flash

```bash
cd re
uvx esphome compile feniska-base.esphome.yaml
uvx esphome upload feniska-base.esphome.yaml --device /dev/cu.usbserial-XXXX   # USB
uvx esphome upload feniska-base.esphome.yaml --device feniska-base.local       # OTA, once ESPHome runs
uvx esphome logs feniska-base.esphome.yaml --device /dev/cu.usbserial-XXXX
```

If you have more than one base, give each a unique `name` substitution in the YAML.

### 4. Add to Home Assistant

Home Assistant normally discovers the device on its own: **Settings → Devices & services → Discovered**. If it doesn't, use **Add integration → ESPHome** with host `feniska-base.local` and port `6053`. Enter the `feniska_api_key` when asked.

### Tare and read

At boot the scale zeroes on whatever is on it, the same as the original firmware. Tare **with the empty litter box standing on the base**, so readings show only the cat and what it leaves behind. Tare again after cleaning or refilling the litter. Drift under 10 g is zeroed out automatically.

```bash
curl -X POST -d '' http://feniska-base.local/button/Tare/press
curl -s http://feniska-base.local/sensor/Weight%20%28live%29
```

Entity names in these URLs are case-sensitive, and the POST needs a body. You can also open `http://feniska-base.local` in a browser.

### Calibration

`calib_fac` in the YAML is the number of raw counts per gram. Every base stores its own factory value in NVS (`feniska/calibFac`); you can read it from your dump, or recalibrate. To recalibrate, read the raw HX711 values (`uvx esphome logs …`) with the base empty and again with a known weight on it, then use:

```
calib_fac = (raw_loaded − raw_empty) / reference_grams
```

The values in `feniska-base.esphome.yaml` are only examples. Put your own base's values in a local override file. `*.local.yaml` is git-ignored, and you build and flash that file instead:

```yaml
# re/my-base.local.yaml
packages:
  base: !include feniska-base.esphome.yaml
substitutions:
  calib_fac: "24.12"   # your base's value
```

On the unit used to develop this, the factory value was 23.76 and recalibration gave 24.12, a 1.5 % difference. Readings vary by about 2–3 % depending on where the load sits on the four corner cells. That's fine for telling cats apart.

## Home Assistant: cat identification

`homeassistant/setup_ha.py` builds on the base's visit sensors and sets up the rest through the Home Assistant API. It needs no YAML files and no add-ons, just a long-lived access token.

**What it creates**

| Entity | Purpose |
|---|---|
| `input_number.<cat>_reference_weight` | the cat's expected weight; adjusts itself slowly from confident matches |
| `input_number.<cat>_last_weight`, `sensor.<cat>_weight` | weight from the cat's last visit; the sensor keeps long-term statistics for weight trends |
| `counter.<cat>_visits_today`, `counter.unknown_litter_visits_today` | daily visit counts, reset at midnight |
| `input_select.litter_box_last_cat` | which cat used the box last; its history doubles as a visit log |
| automation *Litter box - identify cat and count visit* | assigns each visit to the cat with the nearest reference weight, or *Unknown* if it's more than `match_kg` away from every cat |
| dashboard *Cats* | weight and visit tiles per cat, last visit, 30-day weight trend, visit history, litter box weight, calibration and base controls |

**Setup**

1. Flash the ESPHome config and adopt the base in Home Assistant (see above).
2. Create a long-lived access token: HA profile → *Security* → *Long-lived access tokens*. Copy it, then save it to a private file:
   ```bash
   mkdir -p ~/.config/feniska && pbpaste > ~/.config/feniska/ha_token && chmod 600 ~/.config/feniska/ha_token
   ```
   `pbpaste` is macOS; on Linux, use `xclip -o` or paste into an editor.
3. Copy `homeassistant/cats.example.toml` to `homeassistant/cats.local.toml` (it's git-ignored). Set your HA URL and list your cats with rough current weights.
4. Run it. It's safe to re-run: existing helpers and learned weights are kept, and the automations and dashboard are rewritten.
   ```bash
   cd homeassistant
   uvx --with websockets python setup_ha.py
   ```

The script finds the bases' entities on its own, even when HA adds the area name to the entity IDs. **Several bases** work out of the box: the automation listens to every base and takes the weight from the one that saw the visit, `input_select.litter_box_last_box` records which box it was, and the dashboard gets a last-visit and a controls card per base. To use only some of your bases, list their HA device names in `base_devices`.

**Tips**
- With cats less than about 1 kg apart, identification by weight gets unreliable. Tighten `match_kg`, and check the reference weights on the dashboard now and then.
- Set reference weights directly with `uvx python set_weights.py "Cat A=3.2" "Cat B=4.5"`.
- `uvx python recent.py 30` shows live-weight spikes and the last visit, which is useful when a cat was too quick to count (visits need ≥ 5 s above `visit_min_kg`).

## Boot splash

After a restart the display shows `splash_file` (240×135) for `splash_seconds`, then the normal weight screen. The default is a generic logo. To show your cats instead, crop round portraits from your photos and point your local override at the result. Keep personal photos in `*.local.*` files, which are git-ignored:
```bash
cd re
uvx --with pillow python scripts/make_splash.py assets/splash-cats.local.png \
    assets/cat-a.local.jpg:CX,CY,R assets/cat-b.local.jpg:CX,CY,R   # circle around each face, in photo pixels
```
```yaml
# re/my-base.local.yaml
substitutions:
  splash_file: "assets/splash-cats.local.png"
```

## Firmware versions

The config sets `esphome: project: version`, which Home Assistant shows as the device's firmware version (e.g. *1.1.0 (ESPHome 2026.9.1)*). When you change the config and flash it, bump the version and tag the commit `v<version>`, so you can always tell which config a base is running.

| Version | Changes |
|---|---|
| 1.0.0 | First ESPHome release: measuring like the original, display, tare, local web server, on-device visit detection |
| 1.1.0 | Visit detection: baseline from the lowest reading before the visit (a paw on the box no longer makes the cat read light); a visit ends after `visit_end_samples` (10) instead of 3 samples, so stepping half out doesn't split it; project version shown in HA |
| 1.2.0 | Boot splash on the display for the first `splash_seconds` (6) after a restart; `splash_file` selects the image |

## Flashing over Wi-Fi without opening the case

The original firmware installs any image it's pointed at, with no signature check:

```
GET http://<base-ip>/update?deviceuuid=<devUuid>&url=http://<host>/firmware.ota.bin
```

- The server must use plain http and send `Content-Type: application/octet-stream` and a `Content-Length`.
- The image must be smaller than 1,310,720 bytes. ESPHome's `firmware.ota.bin` is about 0.95 MB.
- You need the base's own `devUuid`, which is stored only in that base's NVS. It may also be on a sticker under the base or in the old Feniska app.
- USB stays the safer route. Details are in [`re/FINDINGS.md`](re/FINDINGS.md) §5.

## Restoring the original firmware

```bash
uvx --from esptool esptool --port /dev/cu.usbserial-XXXX write-flash 0 feniska-original.bin
```

## Reverse engineering

The original firmware (v16: Arduino-ESP32, PlatformIO, July 2022) was decompiled with Ghidra 12 (Xtensa). Results, including the function map, measurement logic, MQTT protocol, HTTP routes and the OTA path, are in [`re/FINDINGS.md`](re/FINDINGS.md). To reproduce:

```bash
brew install ghidra
dd if=feniska-original.bin of=app0.bin bs=4096 skip=16 count=320   # app0 partition: 0x10000, 0x140000
python re/esp2elf.py app0.bin re/app0.elf
export JAVA_HOME=$(brew --prefix openjdk@21)/libexec/openjdk.jdk/Contents/Home
$(brew --prefix ghidra)/libexec/support/analyzeHeadless re/proj feniska \
  -import re/app0.elf -processor "Xtensa:LE:32:default" \
  -scriptPath "$PWD/re/scripts" -postScript DumpByStrings.java "$PWD/re/out" "init and start HX711 scale"
```
