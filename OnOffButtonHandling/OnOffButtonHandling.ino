#include "Defines.h"
#include "Variables.h"

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println(F("Setting up"));

  pinMode(ON_OFF_RC_PIN, INPUT);

  Serial.println(F("Setup done"));

  onOffCommand = POWER_IS_OFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  HandleReceiverInput();
  PrintStates();
}


