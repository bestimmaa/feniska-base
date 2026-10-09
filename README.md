# Feniska Base → ESPHome

Revives the **Feniska** smart cat-toilet scale base after the Berlin pet-tech startup behind it shut down. The original firmware only talked to Feniska's AWS cloud, so the bases stopped working when the cloud did. This project reflashes them with [ESPHome](https://esphome.io) so they become local weight sensors for Home Assistant, with no cloud involved.

## What you get

- Weight in kg, using the original firmware's filtering and sending rules (more than 20 g change, then once 10 s later, then every 3 min), plus a live value about once per second
- The weight shown on the built-in display, as before
- Tare, restart and backlight controls in Home Assistant and through a local web API
- The original calibration math, with a simple procedure to recalibrate

Cat-visit detection isn't included. The original device only sent raw weights; recognising visits happened in Feniska's cloud. Build it as a Home Assistant automation on top of the live weight.

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

At boot the scale zeroes on whatever is on it, the same as the original firmware. Tare again if it restarted with something on it:

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
