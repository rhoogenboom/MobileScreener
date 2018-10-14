#include <OSL_SimpleTimer.h>
#include "SoftwareSerial.h"
SoftwareSerial mySerial(10, 11);
#include <PinChangeInterrupt.h>

//variables
//timer
OSL_SimpleTimer timer; //timer object for handling events outside the loop code
unsigned int startEngineTimerID;
unsigned int engineHighTimerID;

//player
int busyPin = 3;
volatile bool playerBusy = false; 

//logic
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
  setVolume(20);

  //TODO initialize timers
  
}


void loop () { 
  //TODO only execute during startup
    //initialize some variables
  if (startUp) {
    delay(2000);
    startUp = false;
    //init timer
    //EngineUp();
    //EngineDown();
      
      //PlayFolderTrack(5, 2);

    demo();
  }

  timer.run();
  //demo();
}

void demo() {
  StartEngine();  
  delay(10000);
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



