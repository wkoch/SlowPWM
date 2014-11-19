# SlowPWM

Arduino library for low frequency PWM, 1 example included.

**Tested on an Arduino Due only.**

## Instructions

Include the library in your sketch:

    #include <SlowPWM.h>

### Constructors

There are 2 constructors which differ by analog resolution.

#### Default

This will create a SlowPWM object with a custom duty-cycle and 10bit analog resolution:

    SlowPWM myPWM(1000, A1, 10);
    // 1000ms duty-cycle, input pin: A1, output pin: 10

#### 12bits Analog Resolution

The same as above, but with 12 bits analog resolution:

    SlowPWM myPWM(1000, A1, 10, 12);
    // 1000ms duty-cycle, input pin: A1, output pin: 10, 12bits.

### Functions

SlowPWM has 3 functions.

#### on()

Starts the PWM the first time it is called, and calls update() automatically.

    myPWM.on();

#### update()

Updates everything inside the library. If you already started your PWM with on(), it will do the PWM until you call stop(). The output will be ON/OFF according to the value on the input. If you adjust the input to 10% with a potentiometer, your output will be on for 10% and off for 90% of the duty-cycle time.

    myPWM.update();

#### off()

Stops the PWM;

    myPWM.off(); // Turns everything off.
