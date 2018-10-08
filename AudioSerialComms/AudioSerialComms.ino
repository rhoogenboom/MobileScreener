#include "SoftwareSerial.h"
SoftwareSerial mySerial(10, 11);
#include <PinChangeInterrupt.h>

int busyPin = 3;
volatile bool playerBusy = false; 
bool startUp = true; 

void setup () {
  Serial.begin (9600); 

  //set pin which reads busy signal from player
  pinMode(busyPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(busyPin), switchBusyState, RISING);
  
  //TODO setup buttons for volume control

  //comms object to player
  mySerial.begin (9600);

  //initialize player
  setVolume(15);

  //TODO initialize timers
  
}


void loop () { 
  //TODO only execute during startup
    //initialize some variables
  if (startUp) {
    startUp = false;
    //EngineUp();
    //delay(15000);
    EngineDown();
  }
  
  //demo();
}

void demo() {
  StartEngine();  
  delay(12000);
  EngineUp();
  delay(12000);
  EngineDown();
  delay(12000);
  StopEngine();
  delay(12000);
  //StartEngine();
}

void StartupPlayer() {
  //wait for valid receiver signal

  //start engine

}



