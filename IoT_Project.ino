/******************************************************************************
 * Using a gas sensor and a display monitor.
 * Displays the sensor's value on both the serial and display monitor.
 * Connects to Adafruit IO for IoT purposes and to show data and a history.
 * Date: July 13th, 2022
 * Author: Michael Loubier
 ******************************************************************************/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "AdafruitIO_WiFi.h"

#define IO_USERNAME "USER"                            // Adafruit IO login
#define IO_KEY      "KEY"
#define WIFI_SSID   "ID"                              // WIFI login
#define WIFI_PASS   "PASS"

#define GAS_PIN 36                                      // Gas sensor is connected to GPIO #36 (pin A4)

#define SCREEN_WIDTH    128                             // OLED display width, in pixels
#define SCREEN_HEIGHT   64                              // OLED display height, in pixels
#define OLED_RESET      32                              // Set reset as pin #32
#define SCREEN_ADDRESS  0x3D                            // 0x3D for 128x64

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
AdafruitIO_Feed *gas = io.feed("gas");                  // Variable for the feed
int gasValue = 0;                                       // Gas sensor value

void setup() {
  pinMode(GAS_PIN, INPUT);                              // Initialize the sensor as input
  
  Serial.begin(115200);
  while(! Serial);                                      // Wait for serial monitor to open
  Serial.println("Connecting to Adafruit IO");
  
  io.connect();                                         // Connecting to Adafruit IO
  while(io.status() < AIO_CONNECTED) {                  // Waiting for the connection
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());                      // Connected to Adafruit IO
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));     // Display error
    for(;;);                                            // Don't proceed, loop forever
  }
  display.display();                                    // Show the Adafruit splash screen
  delay(2000);                                          // Pauses 2 seconds
  display.clearDisplay();                               // Clears the buffer
}

void loop() {
  io.run();
  
  display.setTextSize(3);                               // Set text size
  display.setTextColor(WHITE);                          // Set text color
  display.setCursor(0, 10);                             // Set text position
  display.clearDisplay();
  
  gasValue = analogRead(GAS_PIN);                       // Read gas sensor's value
  Serial.print("sending -> ");
  Serial.println(gasValue);                             // Print gas sensor's value in serial monitor
  
  if(gasValue > 1000){                                  // Gas detected
    display.println("Gas!!!");
    display.println(gasValue);                          // Print gas sensor's value in display monitor
    display.display();
   } else{                                              // No gas detected
    display.println("OK!!!");
    display.println(gasValue);                          // Print gas sensor's value in display monitor
    display.display();
  }
  gas -> save(gasValue);                                // Saving to Adafruit IO feed
  delay(5000);                                          // Pauses 5 seconds
}
