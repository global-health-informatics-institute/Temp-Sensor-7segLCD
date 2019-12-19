# Temp-Sensor-7segLCD
This is a code specifically to read temperature from  the si702 sensor which is connected on esp32 pin 21 and 22 (SDA AND SCL) and display the reading on a 7Segment LCD display
pin.
The si702 sensor reads better at a time space of 500 ms.For th lcd to work properly it requires that the pins be on for 5ms and grounded for 5ms(on and off).
innitially the lcd requires AC power although we are supplying wih DC signal. AND thats why we ground a pin 5 milisecond then turn another pin for another 5milliseconds
