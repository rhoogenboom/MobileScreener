#include <ESC.h>
#include "defines.h"
#include "variables.h"


void setup() {
  //initialize boot vars
  Serial.begin(9600);

  //initiale RC channel values to 0
  for (int i=0; i++; i<RC_CHANNEL_COUNT) {
    timer_start[i] = 0; 
  }

  //initialize pins
  

  //connect receiver and int handlers
  attachInterrupt(digitalPinToInterrupt(HOPPER_RC_PIN), calculateHopperReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BELT_RC_PIN), calculateBeltReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(CRUSHER_RC_PIN), calculateCrusherReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(TRACK_LEFT_RC_PIN), calculateTrackLeftReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(TRACK_RIGHT_RC_PIN), calculateTrackRightReceiverInput, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ON_OFF_PIN), calculateOnOffReceiverInput, CHANGE);

  //connect ESCs
  BeltESC.arm();
  HopperESC.arm();
  CrusherESC.arm();

}

void loop() {
  if (startup) {
    BeltESC.speed(BELT_ESC_STOP);
    HopperESC.speed(HOPPER_ESC_STOP);
    CrusherESC.speed(CRUSHER_ESC_STOP);

    //start crusher engine
    
    startup = false;
  }

  

}
