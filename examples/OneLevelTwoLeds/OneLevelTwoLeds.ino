#include <OnePush.h>
#include <Debounce.h>

// 1 level OnePush button called myButton.
// Each button press will turn led1 On or Off.
// Every 5 presses led2 will turn On until next press.

byte button = 22;
byte led1 = 23;
byte led2 = 25;
OnePush myButton = OnePush(button); // Creates an OnePush button.

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, myButton.state()); // Write the state directly to the led.
  if (myButton.count() > 0 && myButton.count() % 5 == 0) { // Every 5 presses.
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}
