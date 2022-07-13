Linnaeus University

# Project

## Gas Detector

**Michael Loubier**<br/>
**Mike_lou89@hotmail.com**<br/>
**ml226gu**<br/>

July 13th, 2022

Course: Internet of Things Applications<br/>
Professor: Fredrik Ahlgren

# Table of Contents

[1Introduction 1](#_Toc108626609)

[2Theory 2](#_Toc108626610)

[2.1The Display Monitor 2](#_Toc108626611)

[2.2The Gas Sensor 3](#_Toc108626612)

[3Method 4](#_Toc108626613)

[4Result 7](#_Toc108626614)

[5Conclusion 9](#_Toc108626615)

[6References 10](#_Toc108626616)

1. **Introduction**

For my project, I made a system that is used to detect if some kind of gas other than normal is detected. It is using a gas sensor and a display monitor. The sensor&#39;s value is displayed on both the serial and display monitor.

This is an IoT project, so I am connecting to Adafruit IO (browser base) from my EPS32 Feather via WIFI to show data, graphs, and a history.

Message queue telemetry transport (MQTT) is the transport protocol that Adafruit IO uses.

In my setup, I have an Adafruit 938 OLED display and a MQ5 gas sensor with an Adafruit ESP32 Feather.

I tested the system by trying to detect gas and verify that the displays show the right text and values. I also verified that the that Adafruit IO interface in my browser worked.

I made the system detect if some kind of strange gas was in the air. Below a certain value there are no such gases.

I chose this project, because those were the materials I had and wanted to learn how IoT works. How to connect a microcontroller to the internet. I chose a simple project.

This project can be used to detect if abnormal gases are present in a house, a greenhouse, a shed, etc.

1. **Materials**

Here is a list of materials needed for this project:

One Adafruit Huzzah32 ESP32 Feather Board – 188 SEK

One Seeed MQ5 Gas Sensor – 80 SEK

One Adafruit 938 128x64 OLED Display – 210 SEK

One Adafruit 1609 Breadboard – 50 SEK

Many Jumper Wires -10 SEK

Everything was bought on Elfa Distrelec (elfa.se). The total cost is 546 SEK.

More information about the monitor and the gas sensor is available in the theory section below.

1. **Theory**
  1. **The Display Monitor**

The Adafruit OLED display 938 is a monochrome 1,3-inch monitor. It has a resolution of 128 x 64 pixels. The display requires a power supply of 3.3V, but it can also work with 5V. The driver chip on the display can communicate with I2C or SPI or 8-bit parallel setup. SPI is generally faster but requires more pins.

To be able to use the 938-display in Arduino IDE and code something, libraries are required. The Adafruit SSD1306 library and the Adafruit GFX library are required along with their dependencies.

![](RackMultipart20220713-1-ydxtk9_html_a54277c7a34222e7.png)

_Adafruit 938 OLED Display_

OLED displays are relatively new compared to LCDs. They were invented in the mid-1970s by Nobel Prize winners Alan Heeger, Alan MacDiarmed, and Hideki Shirakawa. Both types of displays can be used in the same monitors, but OLED is able to be much thinner, have greater brightness, and better color reproduction. (_explainthatstuff.com/how-oleds-and-leps-work.html_).

  1. **The Gas Sensor**

The MQ5 gas sensor from Seeed is used to detect a wide range of gases like LPG, Butane, Propane, Methane, Alcohol, and Hydrogen. A good way to use the sensor is to detect a gas leakage. The MQ5 sensor has high sensitivity which can be changed with its potentiometer. It also has a fast response time. It also is very stable and can have a long lifespan.

![](RackMultipart20220713-1-ydxtk9_html_5ebf253befa605e.png)The working voltage of the MQ5 gas sensor is between 4.9V to 5.1V. The scope of gases which it can detect is between 200ppm and 10000ppm.

_Seeed Groove MQ5 Gas Sensor_

1. **Method**

After installing Arduino IDE and learning how to connect everything, I started the real work.

![](RackMultipart20220713-1-ydxtk9_html_e0d5200299bd358b.jpg)Firstly, I plugged everything in my setup to the ESP32. My setup looks like this:

**The display is connected so:**

The GND pin is connected to the ground.

The Vin pin is connected to the 3V.

The DATA pin is connected to the SDA.

The CLK pin is connected to the SCL.

The RST pin is connected to the GPIO#32.

**The gas sensor is connected so:**

The GND pin is connected to the ground.

The VCC pin is connected to the 3V.

The SIG pin is connected to the GPIO#36 (A4).

![](RackMultipart20220713-1-ydxtk9_html_18b3109a774cba0f.png)Secondly, I wrote the code for the system using Arduino IDE. Here is what it looks like:

![](RackMultipart20220713-1-ydxtk9_html_6cc5980b659a7120.png)

It detects gas when the sensor&#39;s value is above 1000.

It is important to import all required libraries (AdafruitIO\_WiFi.h, SSD1306, GFX, SPI.h, Wire.h).

I initialized the display object in the code with &quot;Adafruit\_SSD1306 display()&quot; command adding its width and height. Also, it needs the display address 0x3D for 128x64 pixel resolution.

It is also important to set a text size, color, and location so that things are displayed correctly.

The gas sensor reads its value at the beginning of every Loop(). It does so every 5 seconds and sends the data to the cloud (Adafruit IO).

1. **Result**

In my project, the desired system was successfully created and tested.

Here is what is showed on the serial monitor:

![](RackMultipart20220713-1-ydxtk9_html_28d4db8f149fe289.png)

Here is what is showed on the display when the system detects gas:

![](RackMultipart20220713-1-ydxtk9_html_70af8d4460ca20f9.jpg)

![](RackMultipart20220713-1-ydxtk9_html_1cd49b9a641a9233.jpg)Here is what is showed in Adafruit IO browser application when everything is ok:

![](RackMultipart20220713-1-ydxtk9_html_daf66a678369a8b2.jpg)Here is what is showed in Adafruit IO browser application when gas is detected:

1. **Conclusion**

In the end, everything worked well, and my goal was reached. I was able to detect gas with the ESP32 and the MQ5 gas sensor. I was also able to show everything I wanted on the Adafruit 938 OLED display and the Adafruit IO web application.

It was very interesting to see the little monitor display data and the Adafruit IO browser application show data in different feeds like a stream, a chart, and a gauge.

The code I wrote was basic and I did not create the best detector system in the world, but it worked well and could detect gas. Everything was connected through WIFI for IoT purposes.

1. **References**

The websites below were a good help:

_learn.adafruit.com/adafruit-io/Arduino_

_learn.adafruit.com/adafruit-io-basics-esp8266-arduino/example-sketches_

_learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples_

_randomnerdtutorials.com/guide-for-oled-display-with-arduino_

_wiki.seeedstudio.com_

_elfa.se_
