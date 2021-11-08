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
  window = 3;
  delayNum = 1000;
  
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

    // turn the #window leds to green behind the red one
        j=i;
        while (--j >= (i - window)) {
          if(j<0){
            break;
          }else{
            leds[j] = CRGB::Green;
          }
        }

        // close behind windows
        int k = window + 1;
        leds[i - k] = CRGB::Black;

    } else {

      // keep the animation moving with the green leds
      // don't turn on red leds
      // leds[i] = CRGB::Red;
    
      j = i;
      while (--j >= (i - window)) {
        if (j < NUM_LEDS) {
          leds[j] = CRGB::Green;
        }
      }

      // close behind windows
      int k = window + 1;
      if (i - k < NUM_LEDS) {
        leds[i - k] = CRGB::Black;
      }

    }//else

    FastLED.show();
    delay(delayNum);

  }//loop


}//fun IDPL
