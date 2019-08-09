#include <OSL_SimpleTimer.h>
#include "defines.h"
#include "variables.h"
#include <PinChangeInterrupt.h>

void setup() {
  //initialize boot vars
  Serial.begin(9600);
  Serial.println(F("Setting up"));

  //initialize audio player on serial comms
  //SerialMP3Player.begin(9600);
  //Replaced by Serial2
  Serial2.begin(9600);

  attachInterrupt(digitalPinToInterrupt(PLAYER_BUSY_PIN), SetPlayerFree, RISING);

  delay(2500);

  pinMode(RED_PIN, OUTPUT);
  digitalWrite(RED_PIN, 1);
}

void loop() {
  if (startup) {
    Serial.println(F("Startup loop entering"));

    delay(3000);
    setVolume(10);
   
    Serial.println(F("Startup loop completed"));
    startup = false;
    PlayInitializedBeep();
    delay(1000);
    StartEngine();
    delay(10000);
    EngineUp();
    delay(10000);
    EngineDown();
    delay(10000);
    StopEngine();
  }

  timer.run();
}
