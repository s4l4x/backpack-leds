#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 6 

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 5

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
	FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
	FastLED.setBrightness(200);
}

void fadeall() { 
  for (int i = 0; i < NUM_LEDS; i++) { 
    leds[i].nscale8(100); 
  } 
}

int index = 0;
int timer = 0;

void loop() { 
  static uint8_t hue = 40; 
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);
    FastLED.show(); 
    fadeall();
    FastLED.delay(100);
  }
  Serial.print("x");
}
