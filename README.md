# SlowPWM

Extended Arduino library by William Koch for low frequency PWM with analog pin or a variable as input, 2 example included.

**Tested on an Arduino Due & Uno R3.**

## Instructions

Include the library in your sketch:

    #include <SlowPWM.h>

### Constructors

There are 2 constructors which differ by analog resolution and an aditional one for a integer variable as control signal.

#### Default

This will create a SlowPWM object with a custom duty-cycle and 10bit analog resolution:

    SlowPWM myPWM(1000, A1, 10);
    // 1000ms duty-cycle, input pin: A1, output pin: 10

#### 12bits Analog Resolution

The same as above, but with 12 bits analog resolution:

    SlowPWM myPWM(1000, A1, 10, 12);
    // 1000ms duty-cycle, input pin: A1, output pin: 10, 12bits.
	
#### 8bit integer variable Resolution

This will create a SlowPWM object with a custom duty-cycle and 8bit resolution controlled by an integer variable:

	int inputPWM;
    SlowPWM myPWM(1000, &inputPWM, 10);
    // 1000ms duty-cycle, input variable: inputPWM, output pin: 10.

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
