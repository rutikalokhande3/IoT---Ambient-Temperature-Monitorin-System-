🌡️ AmbientIQ — Real-Time IoT Temperature Monitoring

 _Sense the environment. Stream the data. Visualize the intelligence._


⚡ The Idea

What if a tiny sensor could turn environmental data into a live digital dashboard?

**AmbientIQ** bridges the physical and digital worlds by collecting ambient temperature readings through a DHT11 sensor, processing them on an ESP8266, and transmitting the data through MQTT and ThingSpeak.

Instead of simply reading temperature on a sensor, the project creates a connected monitoring pipeline where measurements can be observed, transmitted, and visualized remotely.

> **From sensor signal to cloud visualization — one connected IoT workflow.**

What Makes It Interesting?

| Capability | What it does |
|---|---|
| 🌡️ Environmental Sensing | Collects ambient temperature readings using DHT11 |
| 📡 Wireless Connectivity | Uses ESP8266 Wi-Fi connectivity to transmit sensor data |
| 🔄 MQTT Messaging | Publishes temperature readings to an MQTT topic |
| ☁️ Cloud Integration | Sends readings to ThingSpeak for cloud-based logging |
| 📈 Live Visualization | Displays temperature trends through a ThingSpeak chart |
| 🔍 Message Inspection | Allows MQTT messages to be inspected using MQTT Explorer |

🧠 System Architecture


🔁 Data Flow

1. **Sense:** DHT11 measures the ambient temperature.
2. **Process:** ESP8266 reads the sensor value.
3. **Connect:** The board connects to the configured Wi-Fi network.
4. **Publish:** Temperature readings are published to the configured MQTT topic.
5. **Store:** The device sends temperature data to ThingSpeak.
6. **Visualize:** ThingSpeak displays the collected readings in a time-series chart.

## 🛠️ Tech Stack

| Layer | Technology |
|---|---|
| Microcontroller | ESP8266 ESP-12E |
| Sensor | DHT11 |
| Firmware | Arduino C/C++ |
| Wireless Communication | Wi-Fi |
| Messaging Protocol | MQTT |
| MQTT Broker | Public test broker (`test.mosquitto.org`) |
| Cloud Platform | ThingSpeak |
| MQTT Client | MQTT Explorer |
| Development Environment | Arduino IDE |

## 🔌 Hardware Connections

| DHT11 Module | ESP8266 ESP-12E |
|---|---|
| VCC | 3V3 |
| DATA | D4 |
| GND | GND |



💻 Getting Started

1. Requirements

- ESP8266 ESP-12E development board
- DHT11 temperature sensor module
- Breadboard and jumper wires
- USB cable
- Arduino IDE
- MQTT Explorer

### 2. Install the Dependencies

Install the ESP8266 board package in Arduino IDE and add the following libraries through the Library Manager:


The sketch also uses ESP8266 networking and HTTP libraries provided by the relevant board environment.

### 3. Configure Your Credentials

Before uploading the firmware, configure your Wi-Fi credentials and ThingSpeak Write API key locally.

### 4. Upload the Firmware

1. Connect the ESP8266 to your computer.
2. Open the `.ino` sketch in Arduino IDE.
3. Select the appropriate ESP8266 board and COM port.
4. Verify the sensor pin and credentials.
5. Compile and upload the firmware.
6. Open Serial Monitor to inspect connection status and sensor readings.

5. Observe the Data


📁 Repository Structure


AmbientIQ/
├── code/
│   └── temperature_monitor.ino
├── docs/
│   └── wiring-diagram.png
├── screenshots/
│   ├── thingspeak-dashboard.png
│   └── mqtt-monitor.png
├── .gitignore
└── README.md


Adjust the structure to match your actual files.

## 🔐 Security & Reliability

- Never commit Wi-Fi passwords or API keys.
- Regenerate credentials if they have been exposed.
- Use a private MQTT broker with authentication and TLS for production deployments.
- Handle Wi-Fi disconnections and sensor read failures in the firmware.
- Treat the public MQTT broker as a testing environment, not a production service.

## 🚀 Future Enhancements

- 📉 Humidity monitoring using the DHT11 humidity output
- 🚨 Configurable high-temperature alerts
- 📱 Mobile-friendly monitoring dashboard
- 💾 Local data logging and export
- 🔒 Authenticated MQTT communication over TLS
- 📊 Historical analytics and threshold-based insights
- 🔋 Low-power operation for remote deployments

*These are potential enhancements, not claims about features already implemented.*
🎯 Project Objective

The goal of AmbientIQ is to demonstrate how embedded hardware, wireless communication, messaging protocols, and cloud dashboards can work together in a practical IoT application.

The project provides hands-on experience with sensor interfacing, ESP8266 programming, MQTT communication, cloud data integration, and real-time monitoring workflows.

