# AGENTS.md — Feniska

Reviving two Feniska smart-scale bases (ESP32, from a defunct startup) as cloud-free Home Assistant weight sensors by reflashing them with ESPHome.

## Central hub

**Notion:** https://app.notion.com/p/3f4c5d5fe196816b83dfd5d20fb827d6

Start every task there. It holds device facts, findings, the plan and current status. Follow links from that page; don't rely on stale copies in this repo. Record new findings and status changes back on the Notion page.

## Ground rules

- **Hardware is irreplaceable.** Never erase/write flash, burn eFuses or change security settings without explicit confirmation from the user. Reads (`flash-id`, `read-flash`) are fine when asked.
- **Firmware dumps are sensitive** (Wi-Fi credentials, device IDs, tokens). Keep them out of git (see `.gitignore`) and out of chat/logs.
- Secrets (Wi-Fi, HA API keys, OTA passwords) go in an ignored `secrets.yaml`, never in committed config.
