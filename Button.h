#pragma once

#include "Arduino.h"

class Button {
public:
	Button(int pin, String name, unsigned long bounceTime);

	enum State {
		Released = 0,
		Pressed = 1
	};

	void setPin(int pin);
	void setName(String name);
	void setBounceTime(unsigned long bounceTime);

	State getState();

	void printStateMessage();
	void checkState();
	bool isNewState();
private:
	void setState(State state);
	State readState();

	int _pin;
	String _name;
	unsigned long _bounceTime;
	State _state = State::Released;
	bool _isNewState = false;
};