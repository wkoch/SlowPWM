#include <SlowPWM.h>

// 1 Led PWM.

SlowPWM myLedPWM(1000, A0, 13); // Creates a SlowPWM object.

void setup() {
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  myLedPWM.on();
}
