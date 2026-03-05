# Arduino-Temperature-and-Humidity-Monitor
## Overview
This project is a simple environmental monitoring system built using an Arduino Uno, a DHT11 temperature and humidity sensor, and a 16×2 LCD display. The device periodically reads temperature and humidity data from the sensor and displays the values on the LCD screen.

The goal of this project was to practice basic embedded programming, hardware wiring, and sensor integration using Arduino.

## Features
- Reads temperature and humidity from a DHT11 sensor
- Displays readings on a 16×2 LCD display
- Updates readings every 2 seconds
- Outputs the same readings to the Serial Monitor for debugging
- Displays an error message if the sensor fails to return data

Example LCD output:
```
Temp: 23 C
Hum: 45 %
```

## Hardware Used

- Arduino Uno (ATmega328P)
- DHT11 Temperature and Humidity Sensor
- 16×2 LCD Display (HD44780 compatible)
- 10k potentiometer (for LCD contrast)
- Breadboard
- Jumper wires

## Wiring
### DHT11 Sensor
| DHT11 Pin | Arduino |
| :--- | :---: | 
| VCC	| 5V |
| GND |	GND |
| DATA | Pin 7 |

### LCD Display

The LCD is connected in 4-bit mode using the LiquidCrystal library

| LCD Pin | Arduino Pin |
| :--- | :---: | 
| RS	| 12 |
| EN	| 11 |
| D4 |	5 |
| D5	| 4 |
| D6 |	3 |
| D7 |	2 |
| VSS |	GND |
| VDD | 5V|
| VO |	Potentiometer (contrast control) |

The potentiometer adjusts the brightness (contrast) of the LCD display.

## Software
### Libraries Used

- DHT.h — reads temperature and humidity from the DHT11 sensor

- LiquidCrystal.h — controls the 16×2 LCD display

These can be installed through the Arduino Library Manager.

## How It Works

The program initializes the LCD display and DHT11 sensor in setup().

The LCD briefly displays "Sensor Starting" during initialization.

Every 2 seconds, the program:
-Reads temperature and humidity from the DHT11.
-Checks if the values are valid.
-Displays the values on the LCD screen.
-If the sensor fails to return a reading, the LCD displays "Sensor Error".

The delay is necessary because the DHT11 sensor requires about 2 seconds between readings.

Example Serial Output
```
T = 23.00 C, H = 45.00%
```

The Serial Monitor output is useful for debugging in case the LCD display is not working correctly.

## What I Learned

Through this project I practiced:

- Wiring and troubleshooting LCD displays and sensors
- Using Arduino libraries for hardware components
- Reading environmental sensor data
- Displaying formatted output on an LCD
- Debugging hardware using the Serial Monitor

One issue I encountered was that the LCD appeared blank even though it was powered. This turned out to be a contrast adjustment issue, which was fixed simply by adjusting the potentiometer connected to the LCD's contrast pin.

## Possible Improvements

Some improvements that could be made to this project include:

- Adding Fahrenheit conversion
- Logging data to an SD card
- Displaying min/max temperature values
- Sending data to a web dashboard or IoT platform
- Updating the display without clearing the LCD to reduce flickering
