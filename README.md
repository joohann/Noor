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

## Licentie

Noor is gebouwd op [WLED](https://github.com/Aircoookie/WLED) (MIT licentie).  
Custom GUI © joohann — MIT licentie.
