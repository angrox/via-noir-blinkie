// Via Noir Neopixel Blinkie (c) 2016 Martin Zehetmayer
// based on the work of Shae Erisson, 2013
// released under the GPLv3 to match the rest of the Neopixel library
#include <Adafruit_NeoPixel.h>


// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            3
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Change this variable to adjust your faction:
// (0,255,0) == ENLIGHTENED
// (0,0,255) == RESISTANCE
// (255,0,0) == SPOOFER
uint32_t pulsecolor = pixels.Color(0, 255, 0);
    

int cur_bright; // global setting - changed in various methods!
int bright_diff = 10;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show(); // Initialize all pixels to 'off'
}

void loop() {
  uint8_t i;
  // Default brightness
  cur_bright=20;
  pixels.setBrightness(cur_bright);
  // Go around a few time - circle with 5 active leds
  for(i=0;i<20;i++) {
     colorWipeSingle(pulsecolor, 80, 5); // Green
  }
  // Now pulsate a few times
  for(i=0;i<5;i++) {
    FactionPulse(80, false);
  }
  // This pulse goes to zero brightness
  FactionPulse(80, true);
  // Wait 2 seconds
  delay(2000);
  cur_bright=40;
  pixels.setBrightness(cur_bright);
  // Enlight one pixel after the other until the ring is fully illuminated
  colorWipe(pulsecolor, 1200);
  // Wait a sec
  delay(1000);
  // Pulsate a few times
  for(i=0;i<100;i++) {
    PulseBrightness(5, false, 40);
    pixels.show();
    delay(50);
  }
  // Restart the whole thing in the endless loop
}

//
//  Methods doing the magic
//
void PulseBrightness(uint8_t step, boolean fade, uint8_t maxb) {
  if (fade && (cur_bright+bright_diff) <= step ) {
    cur_bright=0;
  }
  else {
    if (cur_bright >= maxb) {
      bright_diff=-step;
    }
    else if (cur_bright <= 5) {
      bright_diff=step;
    }
    cur_bright=cur_bright+bright_diff;
  }
  pixels.setBrightness(cur_bright); //adjust brightness here
}

void colorWipe(uint32_t c, int wait) {
  for(uint16_t i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, c);
      pixels.show();
      delay(wait);
  }
}

void colorWipeSingle(uint32_t c, uint8_t wait, uint8_t size) {
  int max_pixels=pixels.numPixels();
  int last_pixel=0;
  for(uint16_t i=0; i<max_pixels; i++) {
      last_pixel=i-size;
      if (last_pixel < 0) {
        last_pixel=max_pixels+last_pixel;
      }
      pixels.setPixelColor(last_pixel,pixels.Color(0,0,0));
      pixels.setPixelColor(i, c);
      pixels.show();
      delay(wait);
  }
}

void FactionPulse(uint8_t wait, boolean fade) { 
  uint16_t i,j;
  for(j=0; j<40; j++) {
    PulseBrightness(5, fade, 40);
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, pulsecolor);
    }
    pixels.show();
    delay(wait);
    if (fade && cur_bright == 0) {
      break;
    }
  }
}



