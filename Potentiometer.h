#pragma once

#include "Arduino.h"

class Potentiometer {
public:
	Potentiometer(int pin, String name, float accuracy);

	void setPin(int pin);
	void setName(String name);
	void setAccuracy(float accuracy);

	float getState();

	void printStateMessage();
	void checkState();
	bool isNewState();
private:
	void setState(float state);
	float readState();

	int _pin;
	String _name;
	float _accuracy;
	float _state = 0;
	bool _isNewState = false;
	float _filteredValue = 0;
};