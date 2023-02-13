#include <Button.h>
#include <Potentiometer.h>

Button buttons[3] = {
  Button(13, "Left", 10),
  Button(12, "Middle", 10),
  Button(11, "Right", 10)
};
Potentiometer potentio = {A5, "Potentio", 1.5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 3; i++) {
    buttons[i].checkState();
    if (buttons[i].isNewState()){
      buttons[i].printStateMessage();
    }
  }
  potentio.checkState();
  if (potentio.isNewState()){
    potentio.printStateMessage();
  }
}
