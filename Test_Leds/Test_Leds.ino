#include "defines.h"
#include "variables.h"
#include <EEPROM.h>

//onboard led pin
int ledPin = 13;

void setup() {
//  
  Serial.begin(9600);
//
//  // initialize the LED pin as an output:
//  pinMode(ledPin, OUTPUT);
//  // set button and led pins
//  buttonState = 0;
//  pinMode(SETUP_BUTTON, INPUT);
//  // set one pin to high to provide 5v for the magnet and servo pot meter and to read the setup button
//  pinMode(POWER_5V, OUTPUT);
//  digitalWrite(POWER_5V, HIGH);
//
//  long Temp;
//  // Get EEPROM Initialization value
//  Serial.println("eeprom initial read");
//  eeprom_read(Temp, E_InitNum);
//
//  // If EEPROM has never been initialized before, do so now
//  if (Temp == EEPROM_Init)
//  {
//    Serial.println("eeprom not initialized");
//    Initialize_EEPROM();
//  }
//  else
//  {
//    Serial.println("load eeprom");
//    Load_EEPROM();         
//  }
//
//
//  // check setup pin
//  buttonState = digitalRead(SETUP_BUTTON);
//  Serial.println(buttonState);
//  // switch to setup mode (or light mode)
//  if (buttonState == HIGH) {
//    Serial.println("Setup button pressed, setup mode");
//    
    SetupMode();
//    ReadPotMeters();
//    setupActive = true;
//  }
//  else {
//    Serial.println("Normal mode active");
//    LightMode();
//  }
}

void loop() {

  //set left full
//  analogWrite(MAGNET_LEFT_LED_RED, 255);
//  delay(500);
// 
//  analogWrite(MAGNET_RIGHT_LED_GREEN, 255);
//  delay(500);
//
//  analogWrite(MAGNET_LEFT_LED_RED, 0);
//  delay(500);
//
//  analogWrite(MAGNET_RIGHT_LED_GREEN, 120);
//  delay(500);

//  //test gradatie
//  for (int i=0; i<= 255; i++) {
//    int k = 255;
//
//    analogWrite(MAGNET_LEFT_LED_RED, i);
//    analogWrite(MAGNET_RIGHT_LED_GREEN, k-i);
//    delay(10);
//   
//  }

//  //test functie
//  for (int i=0; i<= 1023; i++) {
//    SetMagnetLEDs(i);
//    delay(10);
//  }

//  SetMagnetLEDs(analogRead(MAGNET_POT));
  delay(500);

  ReadPotMeters();
  

//  // startup code once
//
//
//  // regular loop running here
//
//  // if we are in setup mode, read the setup button
//  if (setupActive == true) {
//    // check setup pin
//    buttonState = digitalRead(SETUP_BUTTON);
//
//    if (buttonState == HIGH) {
//      // turn LED on:
//      digitalWrite(ledPin, HIGH);
//    } else {
//      // turn LED off:
//      digitalWrite(ledPin, LOW);
//    }
//
//    // if the button is pressed, we want to read new pot values and store them in EEPROM
//    if (buttonState == HIGH) {
//      Serial.println("Setup button pressed, update mode");
//      ReadPotMeters();
// 
////      Serial.println("Write updated params to eeprom");
////      Write_EEPROM();      
//
//      //TODO: send servo EEPROM value over to trailer
//    }
//  }
//
//  
////  //TODO add to CalculateRearAxlePosition in PlateControl
////  int potInput = analogRead(A7); //Nano: A7  input: 0-1024 
////  //set magnet LEDs should go in main loop but only when we are in setup mode
////  if (setupActive == true) {
////    SetMagnetLEDs(potInput);
////  }
//  // do the normal handling of inputs 
//
//  // do the normal handling of transmission
}
