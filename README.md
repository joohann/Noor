# نور · Noor

**Aquarium verlichting powered by WLED** — een custom interface voor SK6812 RGBW LED strips met ingebouwde setup wizard en automatische updates.

![Noor GUI](docs/screenshot.png)

---

## Wat is Noor?

Noor (نور, Arabisch voor *licht*) is een custom WLED firmware build met een op maat gemaakte webinterface voor aquarium verlichting. Je bedient je strip via de browser — telefoon, tablet of PC.

**Features:**
- 🧙 Setup wizard bij eerste gebruik (wifi, naam, LED-aantal)
- 🎨 8 aquarium presets (Daglicht, Koraalrif, Maannacht, ...)
- 💧 SK6812 RGBW ondersteuning — aparte witte channel
- ⬆️ Automatische update melding (elke 24 uur)
- 📡 Powered by WLED — alle WLED functies beschikbaar via `/settings`

---

## Hardware

| Onderdeel | Model | Prijs |
|---|---|---|
| Microcontroller | Wemos D1 Mini (ESP8266) | ~€3 |
| LED strip | SK6812 RGBW 60 LED/m IP30 | ~€10/m |
| Level shifter | 74AHCT125 | ~€1 |
| Voeding | 5V / 8–10A | ~€10 |
| Connector | JST SM 4-pin | ~€1 |

**Bedrading:**
```
5V PSU  ──→  Strip VCC
        ──→  Strip GND
        ──→  Wemos 5V

Wemos D4  →  74AHCT125 input
              74AHCT125 output  →  Strip DATA
```

> ⚠️ SK6812 is een **5V strip**. Geen 12V nodig.

---

## Installatie

### Optie 1 — Flash de .bin (makkelijkst)

1. Download de nieuwste `noor-x.x.x-d1_mini.bin` van de [Releases pagina](https://github.com/joohann/noor/releases)
2. Flash via [ESPHome Flasher](https://github.com/esphome/esphome-flasher/releases) of [ESP Flash Download Tool](https://www.espressif.com/en/support/download/other-tools)
3. Verbind met het wifi netwerk **`Noor-Setup`**
4. De setup wizard opent automatisch in je browser

### Optie 2 — Zelf compileren

**Vereisten:** Git, Python 3.11+, Node.js 20+, PlatformIO

```bash
# 1. WLED broncode ophalen
git clone https://github.com/Aircoookie/WLED.git
cd WLED

# 2. Noor GUI toevoegen
git clone https://github.com/joohann/noor.git noor-overlay
cp noor-overlay/wled00/data/index.htm wled00/data/index.htm
cp noor-overlay/platformio.ini platformio.ini

# 3. Compileren & flashen (USB)
pio run -e d1_mini -t upload

# 4. OTA update (wifi)
pio run -e d1_mini_ota -t upload
```

---

## Updates

Noor checkt automatisch elke 24 uur of er een nieuwe versie is via GitHub. Als er een update is verschijnt er een banner in de interface met de changelog. Klik op **Installeren** — de firmware wordt direct via OTA bijgewerkt, geen USB nodig.

Je kunt ook handmatig updaten:
1. Download de nieuwe `.bin` van [Releases](https://github.com/joohann/noor/releases)
2. Ga naar `http://[noor-ip]/update` in je browser
3. Upload het `.bin` bestand

---

## WLED instellingen

Alle WLED instellingen zijn nog steeds bereikbaar via:
- `http://[noor-ip]/settings` — alle WLED opties
- `http://[noor-ip]/json` — JSON API
- `http://[noor-ip]/index` — originele WLED interface

---

## Nieuwe release maken

```bash
git tag v1.1.0
git push origin v1.1.0
```

GitHub Actions bouwt automatisch de firmware en maakt een release aan met de `.bin` als download.

---

## Licentie

Noor is gebouwd op [WLED](https://github.com/Aircoookie/WLED) (MIT licentie).  
Custom GUI © joohann — MIT licentie.
