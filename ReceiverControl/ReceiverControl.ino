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
  pinMode(HOPPER_RC_PIN, INPUT_PULLUP);
  pinMode(BELT_RC_PIN, INPUT_PULLUP);
  pinMode(CRUSHER_RC_PIN, INPUT_PULLUP);
  pinMode(TRACK_LEFT_RC_PIN, INPUT_PULLUP);   
  pinMode(TRACK_RIGHT_RC_PIN, INPUT_PULLUP);   
  pinMode(ON_OFF_PIN, INPUT_PULLUP);   

//  //connect receiver and int handlers
//  attachInterrupt(HOPPER_RC_PIN, calculateHopperReceiverInput, CHANGE);
//  attachInterrupt(BELT_RC_PIN, calculateBeltReceiverInput, CHANGE);
//  attachInterrupt(CRUSHER_RC_PIN, calculateCrusherReceiverInput, CHANGE);
//  attachInterrupt(TRACK_LEFT_RC_PIN, calculateTrackLeftReceiverInput, CHANGE);
//  attachInterrupt(TRACK_RIGHT_RC_PIN, calculateTrackRightReceiverInput, CHANGE);
//  attachInterrupt(ON_OFF_PIN, calculateOnOffReceiverInput, CHANGE);

  //connect ESCs
  BeltESC.arm();
  HopperESC.arm();
  CrusherESC.arm();
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
  PrintChannelValues();
}
