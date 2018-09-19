#include "SoftwareSerial.h"
SoftwareSerial mySerial(10, 11);

boolean playOne = false;
int waitTime = 0;
boolean startup = true;

void setup () {
  mySerial.begin (9600);
  delay(1500);
  playOne = true;
//  waitTime = millis();
//  setVolume(10);
//  playFolderTrack(1, 1);
//  RepeatPlaybackFolder(1);
//  delay(8000);
//  setVolume(15);
//  RepeatPlaybackFolder(2);
//  delay(8000);
  //delay(11000);
  //playFolderTrack(3, 1);
}



void loop () { 
//  if (startup) {
//    startup = false;
//    playNumber(0, 0);
//    delay(5000);
//    playNumber(0, 1);
//    delay(15000);
//    playNumber(0, 2);
//   }
//  if (waitTime+5000 < millis()) {
//    if (waitTime) {
//      playOne = false;
//      playNumber(0,0);
//    } else {
//      playOne = true;
//      playNumber(0,1);
//    }
//    waitTime = millis();
//  }
}

void StartupPlayer() {
  //initialize player variables and states

  //wait for valid receiver signal

  //start engine
  StartEngine();
}


void RepeatPlaybackOn() {
  ExecuteCommand(0x19, 0, 0);
}

void RepeatPlaybackOff() {
  ExecuteCommand(0x19, 0, 1);  
}

void RepeatPlaybackFolder(byte folderNumber) {
  ExecuteCommand(0x17, 0, folderNumber);
}

void specifyPlaybackMode(byte playbackMode)
{
  ExecuteCommand(0x09, 0, playbackMode);
}


void playFolderTrack(byte folderNumber, byte trackNumber)
{
  ExecuteCommand(0x0F, folderNumber, trackNumber);
}

void playNumber(byte highByte, byte lowByte)
{
  ExecuteCommand(0x3F, highByte, lowByte);
//  ExecuteCommand(0x11,0,0); //repeat play
  ExecuteCommand(0x0D,0,0); 
}

void repeatNumber(byte highByte, byte lowByte)
{
  ExecuteCommand(0x3F, highByte, lowByte);
  ExecuteCommand(0x08,0,0); 
}

void playFirst()
{
  ExecuteCommand(0x3F, 0, 0);
  setVolume(10);
  ExecuteCommand(0x11,0,1); 
}

void pause()
{
  ExecuteCommand(0x0E,0,0,false);
}

void play()
{
  ExecuteCommand(0x0D,0,1,false); 
}

void playNext()
{
  ExecuteCommand(0x01,0,1,false);
}

void playPrevious()
{
  ExecuteCommand(0x02,0,1,false);
}

void setVolume(int volume)
{
  ExecuteCommand(0x06, 0, volume, false); // Set the volume (0x00~0x30)
}


