//commandline Items
#define Start_Byte 0x7E
#define Version_Byte 0xFF
#define Command_Length 0x06
#define End_Byte 0xEF
#define Acknowledge 0x00 //Returns info with command 0x41 [0x01: info, 0x00: no info]

//playback modes
#define RepeatPlayback 1
#define FolderRepeatPlayback 2
#define SingleRepeatPlayback 3
#define RandomPlayback 4

void switchBusyState() {
  playerBusy = false;
  Serial.println("...");
}

void wait(unsigned int minimalWaitTime)
{
  playerBusy = true;
  delay(minimalWaitTime);
  while (playerBusy) {
  }
}

void ResetPlayer() {
  ExecuteCommand(0x0C, 0, 0, true);
}

void SleepPlayer() {
  ExecuteCommand(0x0A, 0, 0, false);
  delay(100);
}

void PlayFolderTrack(byte folderNumber, byte trackNumber)
{
  playerBusy = true;
  RepeatPlaybackOff();
  ExecuteCommand(0x0F, folderNumber, trackNumber, true);
}

void RepeatPlaybackFolder(byte folderNumber) {
  playerBusy = true;
  ExecuteCommand(0x17, 0, folderNumber, true);
}

void RepeatPlaybackOn() {
  playerBusy = true;
  ExecuteCommand(0x11, 0, 1, true);
}

void RepeatPlaybackOff() {
  playerBusy = true;
  ExecuteCommand(0x11, 0, 0, true);  
}

void setVolume(int volume)
{
  ExecuteCommand(0x06, 0, volume, true); // Set the volume (0x00~0x30)
}

// Excecute the command with parameters
void ExecuteCommand(byte CMD, byte Par1, byte Par2, bool wait)
{
  // Calculate the checksum (2 bytes)
  word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);

  // Build the command line
  byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge, Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte};
  
  //Send the command line to the module
  for (byte k=0; k<10; k++)
  {
    SerialMP3Player.write( Command_line[k]);
  }
  //wait when we want to
  if (wait) {
    delay(100);
  }
}
