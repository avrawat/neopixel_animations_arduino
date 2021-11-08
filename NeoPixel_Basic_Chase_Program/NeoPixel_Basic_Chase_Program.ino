#include <FastLED.h>

//
//This is a simple LED chase program for the WS2811/2 RGB led strip.
//Connect the data wire to pin 8 of arduino
//


// How many leds in your strip?
#define NUM_LEDS 10
//define the data pin of arduino
#define DATA_PIN 8

int i;
int window;
int j;
int delayNum;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); // GRB ordering is assumed
  // intialise the index
  i = 0;
  // size of the moving window - 9 is the number of green leds
  window = 1;
  delayNum = 500;

}

void loop() {

  newChase();

}

void newChase() {

  // traverse all the leds
  // assume you are travelling to an exteded version of the strip
  for (i = 0; i <= NUM_LEDS + window; i++) {

    // untill we are in the limit

    if (i < NUM_LEDS) {
      // first led to be red
      leds[i] = CRGB::Red;
    }
    // turn the #window leds to green behind the red one
    j = i;
    while (--j >= (i - window)) {
      if (j < 0 || j >= NUM_LEDS) {
        break;
      } else {
        leds[j] = CRGB::Green;
      }
    }

    // close behind windows
    int cls = i - (window + 1);
    if( cls >= 0 && cls < NUM_LEDS){
         leds[cls] = CRGB::Black;
    }

    FastLED.show();
    delay(delayNum);

  }//loop


}//fun IDPL
