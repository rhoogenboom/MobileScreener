#include <OSL_SimpleTimer.h>
#include <SoftwareSerial.h>
#include <ESC.h>
#include "defines.h"
#include "variables.h"
#include <PinChangeInterrupt.h>

//variables
//timer
OSL_SimpleTimer timer; //timer object for handling events outside the loop code
unsigned int timerID;

//player
int busyPin = 21;
volatile bool playerBusy = false; 

//logic
bool startUp = true; 


void setup () {
  Serial.begin (9600); 

  //set pin which reads busy signal from player
  pinMode(busyPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(busyPin), SetPlayerFree, RISING);
  
  //TODO setup buttons for volume control

  //comms object to player
  SerialMP3Player.begin (9600);

  //initialize player
  setVolume(20);

  //TODO initialize timers
  
}


void loop () { 
  //TODO only execute during startup
    //initialize some variables
  if (startUp) {
    timerID = timer.setTimeout(12000, StopPlayingWarningBeep);
    
    delay(1000);
    startUp = false;
    //init timer
    //EngineUp();
    //EngineDown();
      
      //PlayFolderTrack(5, 2);

    demo();
    //StartEngine();
    //delay(3000);
    //StartPlayingWarningBeep();
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



