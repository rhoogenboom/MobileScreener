#include <SoftwareSerial.h>
#include <ESC.h>
#include "defines.h"
#include "variables.h"
#include <PinChangeInterrupt.h>

void setup() {
  //initialize boot vars
  Serial.begin(9600);
  Serial.println(F("Setting up"));

  //initiale RC channel values to 0
  for (int i=0; i<RC_CHANNEL_COUNT; i++ ) {
    timer_start[i] = 0; 
    channel_pulse_time[i] = 0;
  }

  //initialize pins
  //connect receiver and int handlers
  pinMode(HOPPER_RC_PIN, INPUT);
  pinMode(BELT_RC_PIN, INPUT);
  pinMode(CRUSHER_RC_PIN, INPUT);
  pinMode(TRACK_LEFT_RC_PIN, INPUT);   
  pinMode(TRACK_RIGHT_RC_PIN, INPUT);   
  pinMode(ON_OFF_RC_PIN, INPUT);   

  attachInterrupt(digitalPinToInterrupt(HOPPER_RC_PIN), calculateHopperReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BELT_RC_PIN), calculateBeltReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(CRUSHER_RC_PIN), calculateCrusherReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(TRACK_LEFT_RC_PIN), calculateTrackLeftReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(TRACK_RIGHT_RC_PIN), calculateTrackRightReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ON_OFF_RC_PIN), calculateOnOffReceiverInput, CHANGE);

  delay(2500);
  
  //connect ESCs
  BeltESC.arm();
  HopperESC.arm();
  CrusherESC.arm();
  delay(2500);
  Serial.println(F("Setup done"));
}

void loop() {
  if (startup) {
    Serial.println(F("Starting"));
    BeltESC.speed(BELT_ESC_STOP);
    HopperESC.speed(HOPPER_ESC_STOP);
    CrusherESC.speed(CRUSHER_ESC_STOP);

    //start crusher engine
    StartEngine();
    
    Serial.println(F("Started"));
    startup = false;
  }

  HandleReceiverInput();
  PrintDebugOutput();
  //delay(2000);
}
