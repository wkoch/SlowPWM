#include <SlowPWM.h>

// slow PWM with changed frequency depending on inputPWM
int inputPWM;
SlowPWM myLedPWM(1000, &inputPWM, 13); // Creates a SlowPWM object.

// previous time and interval in which inputPWM can change
unsigned long previousMillis = 0;
const long interval = 10000;

void setup() {
  inputPWM = 255;
  pinMode(13, OUTPUT);
}

void loop() {
  myLedPWM.on();

  // do something with inputPWM, i.e,
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    inputPWM -= 100;
    if (inputPWM < 0) {inputPWM = 255;}
  }
  myLedPWM.update();
}
