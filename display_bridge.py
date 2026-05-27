import json
import time
import urllib.parse
import urllib.request

STATE_FILE = "air_dj_display_state.json"
ESP32_IP = "192.168.137.229"
last_sent = ""

def short(text):
    return text[:16]

while True:
    try:
        with open(STATE_FILE, "r", encoding="utf-8") as f:
            state = json.load(f)

        line1 = short(state["deck1_title"])
        line2 = short(state["deck2_title"])

        if state.get("both_playing"):
            flash_on = int(time.time() * 2) % 2 == 0

            if flash_on:
                r, g, b = 255, 0, 0      # red
            else:
                r, g, b = 255, 255, 255  # white
        else:
            r, g, b = 255, 255, 255

        params = urllib.parse.urlencode({
            "line1": line1,
            "line2": line2,
            "r": r,
            "g": g,
            "b": b
        })

        url = f"http://{ESP32_IP}/update?{params}"

        if url != last_sent or state.get("both_playing"):
            urllib.request.urlopen(url, timeout=1).read()
            print("Sent:", line1, "|", line2, "|", r, g, b)
            last_sent = url

        time.sleep(0.25)

    except Exception as e:
        print("Error:", e)
        time.sleep(1)