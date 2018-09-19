#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFPlayerMini_Fast.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFPlayerMini_Fast myDFPlayer;
void printDetail(uint8_t type, int value);
int i;

void setup()
{
  mySoftwareSerial.begin(9600);
//  Serial.begin(115200);
//  
//  Serial.println();
//  Serial.println(F("DFRobot DFPlayer Mini Demo"));
//  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  myDFPlayer.begin(mySoftwareSerial); //Use softwareSerial to communicate with mp3.

//  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
  delay(100);
  i = 0;
  myDFPlayer.loop(2);
  delay(100);
}

void loop()
{
//  static unsigned long timer = millis();
//  
//  if (millis() - timer > 5000) {
//    timer = millis();
//    myDFPlayer.play(i++);  //Play the first mp3
//    if (i == 5) {
//      i = 0;
//    }
//  }
}
