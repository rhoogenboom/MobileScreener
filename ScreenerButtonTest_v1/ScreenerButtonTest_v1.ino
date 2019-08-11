#include <OSL_SimpleTimer.h>
#include <JC_Button.h>
#include "defines.h"
#include "variables.h"
#include <PinChangeInterrupt.h>


void setup() {
  startup = true;
  
  //initialize boot vars
  Serial.begin(9600);
  Serial.println(F("Setting up"));

  //initialize audio player on serial comms
  Serial2.begin(9600);

  attachInterrupt(digitalPinToInterrupt(PLAYER_BUSY_PIN), SetPlayerFree, RISING);

  delay(2500);
  volumeLevel = 10;
}

void loop() {
  if (startup) {
    Serial.println(F("Startup loop entering"));

    delay(3000);
    setVolume(volumeLevel);
   
    Serial.println(F("Startup loop completed"));
    startup = false;
    PlayInitializedBeep();
   }

  volumeUpButton.read();
  volumeDownButton.read();
  powerButton.read();
  lightsButton.read();
  trackLeftForwardButton.read();
  trackLeftBackwardButton.read();
  trackLeftForwardButton.read();
  trackRightBackwardButton.read();

  HandleVolumeButtons();
  HandleOnOffButton();

  timer.run();
}
