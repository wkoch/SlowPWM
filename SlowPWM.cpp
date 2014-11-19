/*
  SlowPWM - v1.0 - 14/11/2014
  Arduino library for low frequency PWM.
  Created by William Koch.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SlowPWM.h"

#define BETWEEN(x, a, b)  ((a) <= (x) && (x) <= (b))

SlowPWM::SlowPWM(unsigned long duty_cycle, byte input, byte output) {
  pinMode(input, INPUT);
  pinMode(output, OUTPUT);
  _duty_cycle = duty_cycle;
  _input = input;
  _output = output;
  _start = 0;
  _status = _active = false;
}

void SlowPWM::on() {
  if (!_status) {
    _status = true;
  }
  SlowPWM::update();
}

void SlowPWM::update() {
  _now = millis();
  if (_status) {
    if (_start >= _end || _start == 0) {
      _high = _start + map(analogRead(_input), 0, 1023, 0, _duty_cycle);
      _end  = _start + _duty_cycle;
      if (_start == 0) {_start = _now;}
    }
    if (_now >= _start && _now <= _high && !_active) {
      digitalWrite(_output, HIGH);
      _active = true;
    } else if (_now > _high && _now < _end && _active) {
      digitalWrite(_output, LOW);
      _active = false;
    } else if (_now >= _end) {
      _start = _end;
    }
  }
}

void SlowPWM::off() {
  if (_status) {
    _status = false;
    digitalWrite(_output, LOW);
  }
}
