# 🎧 Air DJ

Air DJ is a gesture-controlled DJ application that lets users control music using hand movements through a webcam. The project combines computer vision, real-time interaction, and audio controls to create a hands-free DJ experience.

---

## ✨ Features

- 🎵 Play and pause music with gestures
- 🎤 Toggle vocals and instrumentals
- 🎚️ Real-time track progress visualization
- 📷 Webcam-based hand tracking
- 🎛️ Interactive dual-deck DJ interface

---

## 🛠️ Technologies Used

- Python
- MediaPipe
- OpenCV
- Pygame

---

## 💻 Requirements

- Python 3.9 – 3.12
- Webcam
- Windows, macOS, or Linux

---

## 🚀 Installation

### 1. Clone the repository

```bash
git clone https://github.com/yourusername/air-dj.git
cd air-dj
```

---

### 2. Create a Virtual Environment

#### macOS / Linux

```bash
python3 -m venv venv
```

#### Windows

```cmd
python -m venv venv
```

---

### 3. Activate the Virtual Environment

#### macOS / Linux

```bash
source venv/bin/activate
```

#### Windows

```cmd
venv\Scripts\activate
```

---

### 4. Install Dependencies

```bash
pip install -r requirements.txt
```

---

### 5. Run the Project

```bash
python air_dj.py
```

---

## 📷 How It Works

Air DJ uses MediaPipe hand tracking and OpenCV computer vision to detect hand gestures through a webcam feed. These gestures are mapped to DJ controls such as play, pause, and vocal/instrumental toggling in real time.
