# 🛩️ Glider Avionics System

This repository contains the codebase for our **Avionics Team** project—an integrated data collection system for our glider drone. Developed by students at **University of Washington Tacoma**, this system collects weather data, captures periodic images, and logs all relevant sensor data to an onboard SD card using the [Cicerone Board](https://store-usa.arduino.cc/products/cicerone-board) and Arduino Nano.

## 📦 Project Overview

Our onboard system includes:

* 🌦️ **Weather Sensor**: BMP280 for temperature, pressure, and altitude data.
* 💾 **SD Card Logging**: Utilizes the standard Arduino SD module to write timestamped sensor and image data.
* 📸 **Cameras**: ESP32-CAM modules capture photos at intervals to support visual mapping and diagnostics.
* 🧠 **Cicerone Board & Arduino Nano**: The Cicerone Board handles high-speed operations and peripherals, while the Arduino Nano manages sensor reading and system coordination.

The system is designed for autonomous and low-power operation, triggered by flight events or periodic timers.

---

## 🧰 Tech Stack

| Component       | Hardware                      | Description                                            |
| --------------- | ----------------------------- | ------------------------------------------------------ |
| Microcontroller | Cicerone Board + Arduino Nano | Dual-controller setup for reliability and coordination |
| Sensor          | BMP280                        | Measures temperature and pressure                      |
| Storage         | SD Card (Arduino Module)      | Stores logs and images                                 |
| Camera          | ESP32-CAM                     | Captures JPEG snapshots                                |
| Software        | Arduino IDE / C++             | Core firmware for avionics system                      |

---
