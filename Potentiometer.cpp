#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin, String name, float accuracy) {
	setPin(pin);
	setName(name);
	setAccuracy(accuracy);
}

void Potentiometer::setPin(int pin) {
	_pin = pin;
	pinMode(_pin, INPUT);
}

void Potentiometer::setName(String name) {
	_name = name;
}

void Potentiometer::setAccuracy(float accuracy)
{
	_accuracy = accuracy;
}

float Potentiometer::getState()
{
	return _state;
}

void Potentiometer::printStateMessage()
{
	String message = _name + ": ";
	message.concat(_state);
	Serial.println(message);
}

void Potentiometer::checkState()
{
	float nowState = readState();
	float delta = abs(nowState - _state);
	if (delta >= _accuracy) {
		setState(nowState);
	} else if (nowState < _accuracy && _state >= 1e-3) {
		setState(0);
	} else if (nowState > 100 - _accuracy && _state <= 100 - 1e-3) {
		setState(100);
	} else {
		_isNewState = false;
		return;
	}
	_isNewState = true;
}

bool Potentiometer::isNewState()
{
	return _isNewState;
}

void Potentiometer::setState(float state)
{
	_state = state;
}

float Potentiometer::readState()
{
	auto nowValue = (float)analogRead(_pin);
	return nowValue * 100 / 1023;
}
