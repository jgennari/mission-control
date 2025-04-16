/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

#define PIN 6
#define NUM_PIXELS 16

Adafruit_NeoPixel pixels(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600); // Start serial communication at 9600 baud
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("NeoPixel Blinkenlights Ready!"); // Print a message once ready

  pixels.begin(); // INITIALIZE NeoPixel str ip object (REQUIRED)
  pixels.show();  // Turn OFF all pixels ASAP
  randomSeed(analogRead(0)); // Seed the random number generator
}

void loop()
{
  // Iterate through each pixel
  for(int i=0; i<NUM_PIXELS; i++) {
    // Generate a random color
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    uint32_t randomColor = pixels.Color(random(256), random(256), random(256));

    // Decide randomly whether to turn the pixel on (with the random color) or off (black)
    if (random(2) == 1) { // 50% chance
        pixels.setPixelColor(i, randomColor);
    } else {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Off
    }
  }
  pixels.show();   // Send the updated pixel colors to the hardware.

  delay(100); // Wait a bit before the next random pattern
}