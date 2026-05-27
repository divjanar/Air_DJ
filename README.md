# 🎧 Air DJ

Air DJ is a gesture-controlled DJ application that lets users control music using hand movements through a webcam. The project combines computer vision, real-time interaction, and audio controls to create a hands-free DJ experience.

https://youtu.be/nUxXKt4A_b4?si=9zYOzgNk49FzyWnt

https://youtu.be/iQUGrcBfwXY

---

## ✨ Features

- 🎵 Play and pause music with gestures
- 🎤 Toggle vocals and instrumentals
- 🎚️ Real-time track progress visualization
- 📷 Webcam-based hand tracking
- 🎛️ Interactive dual-deck DJ interface
- 📺 ESP32 LCD track display integration
- 🚨 RGB backlight flashes red when both tracks are playing
- 📡 Real-time wireless communication between Air DJ and ESP32

---

## 🛠️ Technologies Used

- Python
- MediaPipe
- OpenCV
- Pygame
- ESP32-C3
- Arduino Framework
- PlatformIO
- I2C LCD Display
- Wi-Fi HTTP Communication

---

## 💻 Requirements

### Software
- Python 3.9 – 3.12
- VS Code
- PlatformIO Extension
- Webcam

### Hardware
- ESP32-C3
- Grove / DFRobot RGB LCD Display
- Jumper wires
- USB-C cable

### Operating Systems
- Windows
- macOS
- Linux

---

# 🔌 ESP32 LCD Integration

Air DJ can connect wirelessly to an ESP32-C3 with a 16x2 RGB LCD display.

The LCD shows:

- Current Deck 1 track
- Current Deck 2 track
- RGB backlight status

When both tracks are playing simultaneously, the LCD backlight flashes red and white.

---

## 🧰 ESP32 Wiring

| LCD Pin | ESP32-C3 Pin |
|---|---|
| SDA | GPIO 8 |
| SCL | GPIO 10 |
| VCC | 3.3V |
| GND | GND |

---

## 🚀 Installation

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/air-dj.git
cd air-dj
```

---

## 2. Create a Virtual Environment

### macOS / Linux

```bash
python3 -m venv venv
```

### Windows

```cmd
python -m venv venv
```

---

## 3. Activate the Virtual Environment

### macOS / Linux

```bash
source venv/bin/activate
```

### Windows

```cmd
venv\Scripts\activate
```

---

## 4. Install Dependencies

```bash
pip install -r requirements.txt
```

---

# 📡 ESP32 Setup

## 1. Install PlatformIO

Install the PlatformIO extension in VS Code.

---

## 2. Open ESP32 Display Project

Open the `air_dj_display` folder in VS Code.

---

## 3. Configure Wi-Fi

Inside `main.cpp`, update:

```cpp
const char* ssid = "AirDJHotspot";
const char* password = "airdj12345";
```

---

## 4. Upload to ESP32

Connect the ESP32-C3 and click:

```text
PlatformIO → Upload
```

After uploading, the LCD will display the ESP32 IP address:

```text
ESP32 IP:
192.168.x.x
```

---

# 🖥️ Running the LCD Bridge

The bridge connects Air DJ to the ESP32 wirelessly.

Inside `display_bridge.py`, set:

```python
ESP32_IP = "YOUR_ESP32_IP"
```

Run the bridge:

```bash
python display_bridge.py
```

---

# ▶️ Run Air DJ

```bash
python air_dj.py
```

---

# 📷 How It Works

Air DJ uses MediaPipe hand tracking and OpenCV computer vision to detect hand gestures through a webcam feed. These gestures are mapped to DJ controls such as play, pause, and vocal/instrumental toggling in real time.

The Python bridge continuously sends track information to the ESP32 over Wi-Fi. The LCD updates in real time with the active track titles while the RGB backlight reacts dynamically to playback states.

---

# 🎛️ ESP32 Display Behavior

| State | LCD Behavior |
|---|---|
| One track playing | White background |
| Both tracks playing | Flashing red/white background |
| Idle | Static white background |

---

# 📂 Project Structure

```text
air-dj-main/
│
├── air_dj.py
├── display_bridge.py
├── air_dj_display_state.json
│
└── air_dj_display/
    ├── src/
    │   └── main.cpp
    └── platformio.ini
```
