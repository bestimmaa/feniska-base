# AGENTS.md — Feniska

Reviving two Feniska smart-scale bases (ESP32, from a defunct startup) as cloud-free Home Assistant weight sensors by reflashing them with ESPHome.

## Central hub

**Notion:** https://app.notion.com/p/3f4c5d5fe196816b83dfd5d20fb827d6

Start every task there. It holds device facts, findings, the plan and current status. Follow links from that page; don't rely on stale copies in this repo. Record new findings and status changes back on the Notion page.

## Ground rules

- **Hardware is irreplaceable.** Never erase/write flash, burn eFuses or change security settings without explicit confirmation from the user. Reads (`flash-id`, `read-flash`) are fine when asked.
- **Firmware dumps are sensitive** (Wi-Fi credentials, device IDs, tokens). Keep them out of git (see `.gitignore`) and out of chat/logs.
- Secrets (Wi-Fi, HA API keys, OTA passwords) go in an ignored `secrets.yaml`, never in committed config.

## Documentation style (public repo)

This repo is public (https://github.com/bestimmaa/feniska-base). Write for any Feniska base owner, not for our two units.

- **Generic only:** no unit-specific data in the repo, including device UUIDs/IDs, MACs, IPs, hostnames of our network, SSIDs, dump hashes or personal details. Use placeholders (`<devUuid>`, `/dev/cu.usbserial-XXXX`, `feniska-original.bin`). Our units' status and specifics belong on the Notion page.
- **Split by audience:** `README.md` = how to back up, flash, calibrate and use a base. `re/FINDINGS.md` = reverse-engineering facts.
- **Evidence-based:** mark findings CONFIRMED (seen in code or on hardware) or INFERRED. Cite firmware version (v16) and function addresses, and keep supporting decompiles/disassembly in `re/out*/`.
- **Reproducible:** every result should come with the command or script that produced it (`re/scripts/`).
- **No binaries:** never commit firmware images, flash dumps or extracted per-device material (AWS certs/keys, NVS contents).
- **Neutral tone:** factual about Feniska and their cloud; the goal is interoperability for owners of orphaned devices.
- Before pushing, grep the diff for anything unit-specific or secret.
