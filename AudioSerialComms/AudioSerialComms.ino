#include "SoftwareSerial.h"
SoftwareSerial mySerial(10, 11);

int busyPin = 3;

void setup () {
//  Serial.begin (9600); 

  //set pin which reads busy signal from player
  pinMode(busyPin, INPUT);

  //TODO setup buttons for volume control

  //comms object to player
  mySerial.begin (9600);

  //initialize player
  setVolume(20);

  //TODO initialize timers
  
}


void loop () { 
  //TODO only execute during startup
    //initialize some variables

  demo();
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



