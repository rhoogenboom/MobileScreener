#include "defines.h"
#include "variables.h"
#include <EEPROM.h>

int buttonState = 0;

void setup() {
  Serial.begin(9600);

  // set button and led pins
  buttonState = 0;
  pinMode(SETUP_BUTTON, INPUT);

  // set one pin to high to provide 5v for the magnet and servo pot meter
  pinMode(POWER_5V, OUTPUT);
  digitalWrite(POWER_5V, HIGH);

  // wait?

  long Temp;
  // Get EEPROM Initialization value
  Serial.println("eeprom initial read");
  eeprom_read(Temp, E_InitNum);

  // If EEPROM has never been initialized before, do so now
  if (Temp == EEPROM_Init)
  {
    Serial.println("eeprom not initialized");
    Initialize_EEPROM();
  }
  else
  {
    Serial.println("load eeprom");
    Load_EEPROM();         
  }


  // check setup pin
  buttonState = digitalRead(SETUP_BUTTON);
  Serial.println(buttonState);
  // switch to setup mode (or light mode)
  if (buttonState == HIGH) {
    Serial.println("Setup button pressed, setup mode");
    SetupMode();
    ReadPotMeters();
    setupActive = true;
  }
  else {
    Serial.println("Normal mode active");
    LightMode();
  }
}

void loop() {
  // startup code once


  // regular loop running here

  // if we are in setup mode, read the setup button
  if (setupActive == true) {
    // check setup pin
    buttonState = digitalRead(SETUP_BUTTON);

    // if the button is pressed, we want to read new pot values and store them in EEPROM
    if (buttonState == HIGH) {
      Serial.println("Setup button pressed, update mode");
      ReadPotMeters();
 
      Serial.println("Write updated params to eeprom");
      Write_EEPROM();      

      //TODO: send servo EEPROM value over to trailer
    }
  }

  
  //TODO add to CalculateRearAxlePosition in PlateControl
  int potInput = analogRead(A7); //Nano: A7  input: 0-1024 
  //set magnet LEDs should go in main loop but only when we are in setup mode
  if (setupActive == true) {
    SetMagnetLEDs(potInput);
  }
  // do the normal handling of inputs 

  // do the normal handling of transmission
}
