# **Environmental Black Box Recorder**



An IoT-based Environmental Monitoring System built using ESP32, DHT11, MQ-2 Gas Sensor, and LDR Sensor. The system continuously monitors environmental conditions and uploads real-time data to ThingSpeak Cloud for visualization and analysis.





##### 📌 Project Overview



The Environmental Black Box Recorder is designed to monitor multiple environmental parameters in real time and provide alerts when abnormal conditions are detected. Inspired by the concept of an aircraft black box, the system records important environmental data that can be used for monitoring, analysis, and preventive safety.



The project uses ESP32 as the central controller and ThingSpeak as the cloud platform for storing and visualizing sensor data.





##### 🚀 Features



\* Real-time Temperature Monitoring

\* Real-time Humidity Monitoring

\* Gas Leak Detection

\* Light Intensity Monitoring

\* Cloud Data Logging using ThingSpeak

\* Visual Alerts using LEDs

\* Audio Alerts using Buzzer

\* Wi-Fi Enabled ESP32 Connectivity

\* Continuous Environmental Surveillance





##### 🛠 Hardware Components



| Component                           | Quantity |

| ----------------------------------- | -------- |

| ESP32 WROOM                         | 1        |

| DHT11 Temperature \& Humidity Sensor | 1        |

| MQ-2 Gas Sensor                     | 1        |

| LDR Module                          | 1        |

| Active Buzzer                       | 1        |

| Red LED                             | 1        |

| Green LED                           | 1        |

| Resistors                           | 2        |

| Breadboard                          | 1        |

| Jumper Wires                        | Multiple |

| USB Cable                           | 1        |



\---



##### 🔌 Circuit Connections



###### DHT11 Sensor



| DHT11 Pin | ESP32 Pin |

| --------- | --------- |

| VCC       | 3.3V      |

| DATA      | GPIO 4    |

| GND       | GND       |



###### LDR Module



| LDR Pin | ESP32 Pin |

| ------- | --------- |

| VCC     | 3.3V      |

| AO      | GPIO 33   |

| GND     | GND       |



###### MQ-2 Gas Sensor



| MQ-2 Pin | ESP32 Pin |

| -------- | --------- |

| VCC      | VIN (5V)  |

| AO       | GPIO 35   |

| GND      | GND       |



###### Alert System



| Device        | ESP32 Pin |

| ------------- | --------- |

| Red LED       | GPIO 14   |

| Green LED     | GPIO 12   |

| Active Buzzer | GPIO 25   |







##### ⚙️ Working Principle



1\. ESP32 reads data from all connected sensors.

2\. Temperature and humidity are measured using the DHT11 sensor.

3\. Gas concentration is monitored using the MQ-2 sensor.

4\. Ambient light intensity is measured using the LDR module.

5\. Sensor data is processed and compared with predefined threshold values.

6\. If abnormal conditions are detected:

&#x20;  \* Red LED turns ON.

&#x20;  \* Buzzer is activated.

7\. During normal conditions:

&#x20;  \* Green LED remains ON.

8\. Sensor readings are uploaded to ThingSpeak Cloud every 20 seconds.

9\. ThingSpeak automatically generates graphs for monitoring and analysis.







##### ☁️ ThingSpeak Integration



The system uploads data to the following fields:



| Field   | Parameter        |

| ------- | ---------------- |

| Field 1 | Temperature (°C) |

| Field 2 | Humidity (%)     |

| Field 3 | Gas Level        |

| Field 4 | Light Level      |







##### 📊 Output



The system provides:



\* Real-time environmental monitoring

\* Cloud-based data visualization

\* Historical data analysis through ThingSpeak charts

\* Instant alert notifications using LEDs and buzzer







##### 📷 Project Images



###### Circuit Setup



images/circuit\_connection.jpg





###### ThingSpeak Dashboard



images/thingspeak\_output.png



##### 💻 Software Requirements



\* Arduino IDE

\* ESP32 Board Package

\* DHT Sensor Library

\* Adafruit Unified Sensor Library

\* ThingSpeak Library





##### 📂 Repository Structure



Environmental-Black-Box-Recorder/

│

├── README.md

├── code/

│   └── environmental\_black\_box.ino

│

├── presentation/

│   └── Environmental\_Black\_Box\_Recorder\_Presentation.pdf

│

├── video/

│   └── project\_demo.mp4

│

├── images/

│   ├── circuit\_connection.jpg

│   └── thingspeak\_output.png

│

└── docs/

&#x20;   └── component\_list.txt









##### 🎯 Applications



\* Smart Homes

\* Agriculture and Farming

\* Industrial Safety

\* Environmental Monitoring

\* Research Laboratories

\* Smart City Infrastructure





##### 🔮 Future Enhancements



\* Soil Moisture Monitoring

\* Water Level Monitoring

\* Tilt Detection

\* Mobile Application Integration

\* Firebase Cloud Database

\* SMS and Email Alert System





##### 👨‍💻 Team Members



**SoilSync Systems – ACE Engineering College**



\* R. Satya Hemesh

\* B. Hari Chandana

\* M. Sasritha

\* N. Sai Gayatri





##### 📄 Project Documentation



The repository contains:



\* Arduino Source Code

\* Project Presentation

\* Project Demonstration Video

\* Circuit Images

\* ThingSpeak Dashboard Output





##### ⭐ Conclusion



The Environmental Black Box Recorder demonstrates the practical implementation of IoT technologies for environmental monitoring. By combining ESP32, multiple sensors, cloud connectivity, and alert mechanisms, the system provides an effective solution for real-time environmental surveillance and safety management.



