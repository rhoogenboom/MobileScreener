#include <SoftwareSerial.h>
#include <ESC.h>
#include "defines.h"
#include "variables.h"
#include <PinChangeInterrupt.h>

void setup() {
  //initialize boot vars
  Serial.begin(9600);
  Serial.println(F("Setting up"));

  //initialize audio player on serial comms
  SerialMP3Player.begin(9600);

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
  //attachInterrupt(digitalPinToInterrupt(ON_OFF_RC_PIN), calculateOnOffReceiverInput, CHANGE);
//redefine on off channel to read busy pin of player
  attachInterrupt(digitalPinToInterrupt(PLAYER_BUSY_PIN), SetPlayerFree, RISING);

  //Read previous volume from EEPROM
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
    delay(3000);
    setVolume(volumeLevel);
    
    Serial.println(F("Startup loop entering"));
    BeltESC.speed(BELT_ESC_STOP);
    HopperESC.speed(HOPPER_ESC_STOP);
    CrusherESC.speed(CRUSHER_ESC_STOP);

    //start crusher engine
    StartEngine();
    onOffCommand = POWER_IS_ON;

    Serial.println(F("Engine started"));
    
    Serial.println(F("Startup loop completed"));
    startup = false;
  }

  HandleReceiverInput();
  PrintDebugOutput();
  //delay(2000);
}
