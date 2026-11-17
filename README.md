# ♻️ Smart Wet and Dry Waste Segregation Dustbin Using Arduino Uno

An Arduino-based Smart Dustbin that automatically detects waste and separates it into Wet and Dry categories using an ultrasonic sensor, FC-28 soil moisture sensor, and SG90 micro servo motor.

## 📌 Project Overview

The Smart Wet and Dry Dustbin is designed to reduce manual waste segregation and make waste management easier.

The system uses an ultrasonic sensor to detect incoming waste and an FC-28 moisture sensor to check whether the waste is wet or dry. Based on the moisture reading, an Arduino Uno controls an SG90 servo motor to rotate a sorting flap and direct waste into the appropriate compartment.

## ✨ Features

- Automatic waste detection using an ultrasonic sensor.
- Wet and dry waste identification using an FC-28 moisture sensor.
- Automatic waste sorting using an SG90 micro servo.
- Two separate waste compartments.
- Arduino-based automation.
- Adjustable moisture threshold.
- Low-cost and beginner-friendly electronics project.

## 🛠️ Components Required

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| FC-28 Soil Moisture Sensor | 1 |
| SG90 Micro Servo Motor | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |
| External regulated 5V power supply | 1 |
| Dustbin with two compartments | 1 |

## 🔌 Circuit Connections

### 1. HC-SR04 Ultrasonic Sensor

| Sensor Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D7 |
| ECHO | D8 |

### 2. FC-28 Moisture Sensor

| Sensor Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| AO | A0 |
| DO | Not Connected |

### 3. SG90 Servo Motor

| Servo Wire | Connection |
|---|---|
| Brown / Black | GND |
| Red | External regulated 5V |
| Orange / Yellow | D6 |

**Important:** Connect the external servo power supply GND to Arduino GND. Keep the electronics protected from water.

## ⚙️ Working Principle

1. The ultrasonic sensor detects waste within the configured detection distance.
2. The FC-28 moisture sensor measures the moisture level of the waste.
3. Arduino Uno processes the analog moisture reading.
4. If the reading indicates wet waste, the servo rotates the sorting flap toward the wet compartment.
5. If the reading indicates dry waste, the servo rotates the flap toward the dry compartment.
6. After sorting, the servo returns to its center position.

## 📊 System Configuration

| Parameter | Default Value |
|---|---:|
| Waste detection distance | 20 cm |
| Ultrasonic trigger pin | D7 |
| Ultrasonic echo pin | D8 |
| Moisture sensor pin | A0 |
| Servo signal pin | D6 |
| Servo center position | 90° |
| Wet waste position | 35° |
| Dry waste position | 145° |
| Moisture threshold | 500 |

*Note: Moisture threshold must be calibrated according to your FC-28 sensor readings.*

## 💻 Software Requirements

- Arduino IDE
- Arduino Uno board package
- Servo.h library (included with the Arduino AVR core)

## 🚀 Installation and Setup

1. Download or clone this repository.
2. Install Arduino IDE.
3. Connect Arduino Uno to your computer using a USB cable.
4. Open the Arduino source code (`.ino`) file.
5. Select **Tools → Board → Arduino Uno**.
6. Select the correct COM port.
7. Verify the circuit connections.
8. Upload the code to Arduino Uno.
9. Open Serial Monitor at 9600 baud.
10. Calibrate the moisture threshold and test the sorting mechanism.

## 🧪 Testing and Calibration

The FC-28 sensor readings vary depending on the sensor, material, and contact conditions.

Test the sensor with dry and wet materials and record the readings.

Adjust the following variable in the Arduino code:

```cpp
int MOISTURE_THRESHOLD = 500;
```

If your sensor gives lower readings for wet materials, use:

```cpp
const bool WET_READING_IS_LOWER = true;
```

If your sensor gives higher readings for wet materials, use:

```cpp
const bool WET_READING_IS_LOWER = false;
```

## 📁 Project Structure

```text
Smart-Wet-Dry-Dustbin/
│
├── README.md
├── Smart_Wet_Dry_Dustbin.ino
│
├── images/
│   ├── project.jpg
│   ├── circuit-diagram.png
│   └── dustbin-design.jpg
│
└── LICENSE
```

## 🔮 Future Improvements

- Add an LCD display to show waste classification.
- Add a buzzer for waste detection alerts.
- Add Wi-Fi monitoring using ESP8266 or ESP32.
- Add waste collection level monitoring.
- Improve waste classification accuracy.
- Add automatic lid opening.

## ⚠️ Limitations

- The moisture sensor must physically contact the waste.
- Moisture detection does not identify recyclability or material type.
- Some materials may be classified incorrectly.
- Servo angles depend on the mechanical sorting flap design.

## 👨‍💻 Author

**Anand Mahato**

GitHub: [IamAnandMahato](https://github.com/IamAnandMahato)

## 📜 License

This project is available under the MIT License.

You are welcome to use, modify, and improve this project for educational and personal purposes.

---

⭐ If you find this project useful, consider giving this repository a star!
