#include "Arduino.h"
#include "Button.h"

Button::Button(int pin, String name, unsigned long bounceTime) {
	setPin(pin);
	setName(name);
	setBounceTime(bounceTime);
}

void Button::setPin(int pin) { 
	_pin = pin;
	pinMode(_pin, INPUT);
}

void Button::setName(String name) {
	_name = name;
}

void Button::setBounceTime(unsigned long bounceTime) {
	_bounceTime = bounceTime;
}

State Button::getState()
{
	return _state;
}

void Button::printStateMessage()
{
	String state = _state == State::Pressed
		? "Pressed" : "Released";
	String message = _name + ": " + state;
	Serial.println(message);
}

void Button::checkState() {
	auto nowState = readState();
	if (nowState != _state) {
		delay(_bounceTime);
		nowState = readState();
		if (nowState != _state) {
			setState(nowState);
			_isNewState = true;
		}		
	} else {
		_isNewState = false;
	}
}

bool Button::isNewState()
{
	return _isNewState;
}

void Button::setState(State state) {
	_state = state;
}

Button::State Button::readState() {
	int state = digitalRead(_pin);
	return static_cast<State>(state);
}
