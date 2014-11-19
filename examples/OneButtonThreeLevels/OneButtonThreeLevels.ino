#include <OnePush.h>
#include <Debounce.h>

// A button with 3 levels called myButton.
// Each of the three leds is turned on on each level.
// Level 0 has nothing, but could be used the same way.

#define level(l, x)  digitalWrite(l, myButton.level() == x ? HIGH : LOW)

byte button = 22;
byte led1 = 23;
byte led2 = 25;
byte led3 = 27;
OnePush myButton = OnePush(button, 3); // Creates an OnePush button.

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  myButton.update(); // Check the button state every update.
  level(led3, 1); // Turns Led3 On on level 1.
  level(led2, 2); // Turns Led2 On on level 2.
  level(led1, 3); // Turns Led1 On on level 3.
}
