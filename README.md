# IoT Project

## Gas Detector

**Michael Loubier**<br/>
**Mike_lou89@hotmail.com**<br/>
**ml226gu**<br/>

Linnaeus University<br/>
July 13th, 2022

Course: Internet of Things Applications<br/>
Professor: Fredrik Ahlgren

# Table of Contents

- [1 Introduction](#introduction)
- [2 Materials](#materials)
- [3 Theory](#theory)
- [3.1 Display Monitor](#display-monitor)
- [3.2 Gas Sensor](#gas-sensor)
- [4 Method](#method)
- [5 Result](#result)
- [6 Conclusion](#conclusion)
- [7 References](#references)

## Introduction

For my project, I made a system that is used to detect if some kind of gas other than normal is detected. It is using a gas sensor and a display monitor. The sensor&#39;s value is displayed on both the serial and display monitor.

This is an IoT project, so I am connecting to Adafruit IO (browser base) from my EPS32 Feather via WIFI to show data, graphs, and a history.

Message queue telemetry transport (MQTT) is the transport protocol that Adafruit IO uses.

In my setup, I have an Adafruit 938 OLED display and a MQ5 gas sensor with an Adafruit ESP32 Feather.

I tested the system by trying to detect gas and verify that the displays show the right text and values. I also verified that the Adafruit IO interface in my browser worked.

I made the system detect if some kind of strange gas was in the air. Below a certain value there are no such gases.

I chose this project, because those were the materials I had and wanted to learn how IoT works. How to connect a microcontroller to the internet. I chose a simple project and it took me about a week long to research and finish.

This project can be used to detect if abnormal gases are present in a house, a greenhouse, a shed, etc.

## Materials

Here is a list of materials needed for this project:

- One Adafruit Huzzah32 ESP32 Feather Board – 188 SEK
- One Seeed MQ5 Gas Sensor – 80 SEK
- One Adafruit 938 128x64 OLED Display – 210 SEK
- One Adafruit 1609 Breadboard – 50 SEK
- Many Jumper Wires -10 SEK

Everything was bought on Elfa Distrelec (elfa.se). The total cost is 546 SEK.

More information about the monitor and the gas sensor is available in the theory section below.

## Theory
  ### Display Monitor

The Adafruit OLED display 938 is a monochrome 1,3-inch monitor. It has a resolution of 128 x 64 pixels. The display requires a power supply of 3.3V, but it can also work with 5V. The driver chip on the display can communicate with I2C or SPI or 8-bit parallel setup. SPI is generally faster but requires more pins.

To be able to use the 938-display in Arduino IDE and code something, libraries are required. The Adafruit SSD1306 library and the Adafruit GFX library are required along with their dependencies.

OLED displays are relatively new compared to LCDs. They were invented in the mid-1970s by Nobel Prize winners Alan Heeger, Alan MacDiarmed, and Hideki Shirakawa. Both types of displays can be used in the same monitors, but OLED is able to be much thinner, have greater brightness, and better color reproduction. (_explainthatstuff.com/how-oleds-and-leps-work.html_).

  ### Gas Sensor

The MQ5 gas sensor from Seeed is used to detect a wide range of gases like LPG, Butane, Propane, Methane, Alcohol, and Hydrogen. A good way to use the sensor is to detect a gas leakage. The MQ5 sensor has high sensitivity which can be changed with its potentiometer. It also has a fast response time. It also is very stable and can have a long lifespan.

The working voltage of the MQ5 gas sensor is between 4.9V to 5.1V. The scope of gases which it can detect is between 200ppm and 10000ppm.

## Method

After installing Arduino IDE and learning how to connect everything, I started the real work.

Firstly, my circuit looks a bit like this:<br/>
![](https://github.com/Sozyone/IoT-Gas-Project/blob/main/Circuit.png)

But below is an actual picture and a definition of how it is connected.
![](https://github.com/Sozyone/IoT-Gas-Project/blob/main/OK.jpg)

**The display is connected so:**

The GND pin is connected to the ground.<br/>
The Vin pin is connected to the 3V.<br/>
The DATA pin is connected to the SDA.<br/>
The CLK pin is connected to the SCL.<br/>
The RST pin is connected to the GPIO#32.<br/>

**The gas sensor is connected so:**

The GND pin is connected to the ground.<br/>
The VCC pin is connected to the 3V.<br/>
The SIG pin is connected to the GPIO#36 (A4).<br/>

Secondly, I wrote the code for the system using Arduino IDE. Here is what it looks like:
![](https://github.com/Sozyone/IoT-Gas-Project/blob/main/Code1.png)
![](https://github.com/Sozyone/IoT-Gas-Project/blob/main/Code2.png)

It detects gas when the sensor&#39;s value is above 1000.

It is important to import all required libraries (AdafruitIO\_WiFi.h, SSD1306, GFX, SPI.h, Wire.h).

I initialized the display object in the code with &quot;Adafruit\_SSD1306 display()&quot; command adding its width and height. Also, it needs the display address 0x3D for 128x64 pixel resolution.

It is also important to set a text size, color, and location so that things are displayed correctly.

The gas sensor reads its value at the beginning of every Loop(). It does so every 5 seconds and sends the data to the cloud (Adafruit IO).

## Result

In my project, the desired system was successfully created and tested.

Here is what is showed on the serial monitor:

![](https://github.com/Sozyone/IoT-Gas-Project/blob/main/Serial.png) 

Here is what is showed on the display when the system detects gas:

![](https://github.com/Sozyone/IoT-Gas-Project/blob/main/Gas.jpg)

Here is what is showed in Adafruit IO browser application when everything is ok:
![](https://github.com/Sozyone/IoT-Gas-Project/blob/main/Adafruit%20IO%20OK.jpeg)

I chose to have a gauge showing the gas sensor value.<br/>
I also have a line chart and a stream for keeping a history of those values with time stamps.

Here is what is showed in Adafruit IO browser application when gas is detected:
![](https://github.com/Sozyone/IoT-Gas-Project/blob/main/Adafruit%20IO%20Gas.jpeg)

## Conclusion

In the end, everything worked well, and my goal was reached. I was able to detect gas with the ESP32 and the MQ5 gas sensor. I was also able to show everything I wanted on the Adafruit 938 OLED display and the Adafruit IO web application.

It was very interesting to see the little monitor display data and the Adafruit IO browser application show data in different feeds like a stream, a chart, and a gauge.

The code I wrote was basic and I did not create the best detector system in the world, but it worked well and could detect gas. Everything was connected through WIFI for IoT purposes.

## References

The websites below were a good help:

_learn.adafruit.com/adafruit-io/Arduino_<br/>
_learn.adafruit.com/adafruit-io-basics-esp8266-arduino/example-sketches_<br/>
_learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples_<br/>
_docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax_<br/>
_randomnerdtutorials.com/guide-for-oled-display-with-arduino_<br/>
_wiki.seeedstudio.com_<br/>
_elfa.se_<br/>
