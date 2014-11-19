/*
  SlowPWM - v1.0.1 - 19/11/2014
  Arduino library for low frequency PWM.
  Created by William Koch.
  Released into the public domain.
*/

#ifndef SlowPWM_h
#define SlowPWM_h

#include "Arduino.h"

class SlowPWM {
  public:
    SlowPWM(unsigned long duty_cycle, byte input, byte output);
    SlowPWM(unsigned long duty_cycle, byte input, byte output, byte bits);

    void on();
    void off();
    void update();
  private:
    unsigned long _duty_cycle, _start, _high, _end, _now;
    int _res;
    byte _input, _output;
    boolean _status, _active;
};

#endif
