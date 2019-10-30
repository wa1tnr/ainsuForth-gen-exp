// Wed Oct 30 18:57:28 UTC 2019
// 4737-a3d-00a- // ainsuForth-gen-exp

// On branch testing-aa- / pre-release of 0.1.0

// Mon Jan 15 18:14:33 UTC 2018
// 4737-a0d-05c-

// Sat Jul 29 18:14:02 UTC 2017
// 4735-b0b-01-

#include <Adafruit_DotStar.h>

#define NUMPIXELS 1 // Number of LEDs in strip

// pinouts for Trinket M0 dotstar are now the defaults, 30 October 2019:
#define DATAPIN    7 // #define DATAPIN    3  // D3 is probably for Gemma M0, unchecked
#define CLOCKPIN   8 // #define CLOCKPIN   4  // D4 is probably for Gemma M0, unchecked

Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

void setup_dotstar() {
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
}

int      head  = 0, tail = -3;  // Index of first 'on' and 'off' pixels
uint32_t color = 0x010000;      // 'On' color (starts red)

void loop_dotstar() {
  strip.setPixelColor(head, color); // 'On' pixel at head
  strip.setPixelColor(tail, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(20);                        // Pause 20 milliseconds (~50 FPS)

  if(++head >= NUMPIXELS) {         // Increment head index.  Off end of strip?
    head = 0;                       //  Yes, reset head index to start
    if((color >>= 8) == 0)          //  Next color (R->G->B) ... past blue now?
      color = 0x010000;             //   Yes, reset to red
  }
  if(++tail >= NUMPIXELS) tail = 0; // Increment, reset tail index

Serial.println("\r\nWent off tail.  Bye from dotstar.");

}

// END
