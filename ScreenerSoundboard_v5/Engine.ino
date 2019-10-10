#define EngineVersion 3

#define EngineStartFolder 1
#define EngineLowFolder 2
#define EngineUpFolder 3
#define EngineHighFolder 4
#define EngineDownFolder 5
#define EngineStopFolder 6
#define InitializedBeep 7

#define WarningBeepTrackNumber 1

void StartPlayingWarningBeep() {
  if (!crusherIsMoving) {
    Serial.println(F("StartPlayingIntercut(WarningBeepTrackNumber)"));
    StartPlayingIntercut(WarningBeepTrackNumber);
  }
}

void StopPlayingWarningBeep() {
  if (crusherIsMoving) {
    Serial.println(F("StopPlayingIntercut()"));
    StopPlayingIntercut();
  }
}

void PlayInitializedBeep() {
  Serial.println(F("PlayFolderTrack(InitializedBeep, EngineVersion)"));
  PlayFolderTrack(InitializedBeep, EngineVersion);
}

void StartEngine() {
  if (!engineIsRunning) {
    CreateQBTimer();
    engineIsRunningHigh = false;
    engineIsRunning = true;

    StartSlowGreenBlink();
    //Play startup
    Serial.println(F("PlayFolderTrack(EngineStartFolder, EngineVersion)"));
    PlayFolderTrack(EngineStartFolder, EngineVersion);
    //always wait 1 sec to allow the player to start playing

    //Wait till ready / delay Xms
    wait(1);//wait(500);

    //Start loop engine low
    Serial.println(F("RepeatPlaybackFolder(EngineLowFolder)"));
    RepeatPlaybackFolder(EngineLowFolder);
  }
}

void EngineUp() {
  StopSlowGreenBlink();
  StartQuickRedBlink();
  //Play rev up
  Serial.println(F("PlayFolderTrack(EngineUpFolder, EngineVersion)"));
  PlayFolderTrack(EngineUpFolder, EngineVersion);
  //Wait till ready / delay Xms
  wait(1);//wait(1500);

  //Start loop engine high
  Serial.println(F("RepeatPlaybackFolder(EngineHighFolder)"));
  RepeatPlaybackFolder(EngineHighFolder);
  engineIsRunningHigh = true;
}

void EngineDown() {
  //Play rev down
  Serial.println(F("PlayFolderTrack(EngineDownFolder, EngineVersion)"));
  PlayFolderTrack(EngineDownFolder, EngineVersion);

  //Wait till ready / delay Xms
  wait(1);//wait(2500);

  //Start loop engine low
  Serial.println(F("RepeatPlaybackFolder(EngineLowFolder)"));
  RepeatPlaybackFolder(EngineLowFolder);
  StopQuickRedBlink();
  engineIsRunningHigh = false;
  StartSlowGreenBlink();
}

void StopEngine() {
  if (engineIsRunning) {
    //check if engine is high
    if (engineIsRunningHigh) {
      EngineDown();
    }
    //Play engine stop
    Serial.println(F("PlayFolderTrack(EngineStopFolder, EngineVersion)"));
    PlayFolderTrack(EngineStopFolder, EngineVersion);
    wait(1);//wait(1500);
    engineIsRunning = false;
    StopSlowGreenBlink();
  }
}

bool PlaySequence(int sequenceLength, int sequence[5]) {
  for (int i = 0; i < sequenceLength; i++) {
    //Play sequence item

    //Play folder sequence[i];

    //Wait till ready / delay Xms

  }
  return true;
}

bool PlaySequenceAndLoop(int sequenceLength, int sequence[5]) {
  for (int i = 0; i < sequenceLength - 1; i++) {
    //Play sequence item

    //Play folder sequence[i];

    //Wait till ready / delay Xms
  }
  //PlayLoop last item from sequence

  return true;
}


