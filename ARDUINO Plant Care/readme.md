# 🌿 Smart Plant Care System (Arduino IoT Cloud + NeoPixel Visual Alerts)

A **Smart Plant Monitoring System** that keeps your plant healthy and happy!  
It monitors **soil moisture**, **temperature**, and **light levels**, then displays your plant’s status using a **NeoPixel color indicator**.  
You can also view all sensor readings on the **Arduino IoT Cloud Dashboard** and even **trigger watering or lighting remotely** 🌱💧☀️

---

## 🧠 Features

- 🌱 **Detects soil moisture** using a soil moisture sensor  
- ☀️ **Measures light level** using an LDR  
- 🌡️ **Reads temperature** using a DHT11/DHT22 sensor  
- 🟢 **NeoPixel color indicator**:
  - 🟩 Green → Everything is perfect  
  - 🟥 Red → Soil too dry, needs watering  
  - 🟦 Blue → Too cold  
  - 🟨 Yellow → Too little light  
- 📲 **Arduino IoT Cloud integration**:
  - View live readings from anywhere  
  - Manually trigger watering or lighting remotely  

---

## 💡 Components Needed

| Component | Description |
|------------|-------------|
| Arduino Uno / MKR WiFi 1010 / ESP32 | Any board compatible with Arduino IoT Cloud |
| Soil Moisture Sensor | Measures soil humidity |
| LDR (Light Dependent Resistor) | Detects light intensity |
| DHT11 or DHT22 | Reads air temperature |
| NeoPixel (or RGB LED) | Displays plant status using colors |
| Jumper Wires & Breadboard | For connections |
| Arduino IoT Cloud Account | To visualize data and control remotely |

---

## ⚙️ Arduino IoT Cloud Variables

| Variable | Type | Permission | Description |
|-----------|------|-------------|-------------|
| `temperature` | float | READ | Current air temperature |
| `soilMoisture` | int | READ | Current soil moisture level |
| `lightLevel` | int | READ | Ambient light intensity |
| `waterPlant` | bool | READ/WRITE | Manual trigger for watering the plant |

---

## 🔌 Circuit Connections

| Sensor/Component | Arduino Pin |
|------------------|-------------|
| DHT11/DHT22 Data | D2 |
| Soil Moisture Sensor | A0 |
| LDR | A1 |
| NeoPixel DIN | D6 |
| VCC & GND | 5V & GND |

---

## 🧩 How It Works

1. The Arduino reads sensor data every 2 seconds:
   - Temperature from DHT11/DHT22  
   - Soil moisture from analog input  
   - Light level from LDR  
2. Based on thresholds, it sets the NeoPixel color:
   - 🟥 Red for dry soil  
   - 🟦 Blue for cold temperature  
   - 🟨 Yellow for low light  
   - 🟩 Green for healthy conditions  
3. Data syncs with Arduino IoT Cloud for live monitoring.  
4. The `waterPlant` variable can be toggled remotely to simulate watering.  

---

## 🧠 Code Overview

The main logic:
```cpp
if (soilMoisture > 800)
  color = strip.Color(255, 0, 0); // Red: Dry soil
else if (temperature < 15)
  color = strip.Color(0, 0, 255); // Blue: Cold
else if (lightLevel < 300)
  color = strip.Color(255, 255, 0); // Yellow: Low light
else
  color = strip.Color(0, 255, 0); // Green: Good