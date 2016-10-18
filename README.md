# via-noir-blinkie
A Arduino Neopixelring project to build a pulsating and rotating lightcircle (for the Via Noir Ingress Anomaly)

This is the code to rotate and pulse the leds of a Neopixel Ring (I used a 12 led ring) in the faction color of an Ingress agent. The idea came up when the Anomaly series "Via Noir" was announced to be played at night. 


## To Build
You need a Neopixel Ring (for example the 12 led ring: https://www.adafruit.com/product/1643) and an Arduino Nano (for the size, https://www.arduino.cc/en/Main/ArduinoBoardNano). 

The build is very simple: Connect the 5V and GND Pin to the corresponsing Pins on the NeoPixel ring and use one digital port on your Arduino Nano as the "Data In" port. Solder it. Download the sketch, compile it with the Arduino IDE and upload it to your Board. 

Further documentation can be found here: https://www.arduino.cc/en/Guide/HomePage

See the prototype (with an Arduino Uno) in action: https://www.youtube.com/watch?v=Dfme6pxks3U

**Have fun**

