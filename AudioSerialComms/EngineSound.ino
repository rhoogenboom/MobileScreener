bool engineIsRunningHigh = false;
bool engineIsRunning = false;

#define EngineVersion 2

#define EngineStartFolder 1
#define EngineLowFolder 2
#define EngineUpFolder 3
#define EngineHighFolder 4
#define EngineDownFolder 5
#define EngineStopFolder 6

void StartEngine() {
  engineIsRunningHigh = false;
  engineIsRunning = true;
  
  //Play startup
  PlayFolderTrack(EngineStartFolder, EngineVersion);
  //always wait 1 sec to allow the player to start playing
 
  //Wait till ready / delay Xms
  wait(1500);

  //Start loop engine low
  RepeatPlaybackFolder(EngineLowFolder);
}

void EngineUp() {
  //Play rev up
  PlayFolderTrack(EngineUpFolder, EngineVersion);
  //Wait till ready / delay Xms
  wait(1500);
  
  //Start loop engine high
  RepeatPlaybackFolder(EngineHighFolder);
  engineIsRunningHigh = true;
}

void EngineDown() {
  //Play rev down
  PlayFolderTrack(EngineDownFolder, EngineVersion);
 
  //Wait till ready / delay Xms
  wait(2500);
  
  //Start loop engine low
  RepeatPlaybackFolder(EngineLowFolder);
  engineIsRunningHigh = false;
}

void StopEngine() {
  //check if engine is high
  if (engineIsRunningHigh) {
    EngineDown();

    //Wait till ready / delay Xms
    engineIsRunningHigh = false;
  } 
  engineIsRunning = false;
  //Play engine stop
  PlayFolderTrack(EngineStopFolder, EngineVersion);
  wait(1500);
}

bool PlaySequence(int sequenceLength, int sequence[5]) {
  for (int i=0; i < sequenceLength; i++) {
    //Play sequence item
    
    //Play folder sequence[i];

    //Wait till ready / delay Xms
  
  }
  return true;
}

bool PlaySequenceAndLoop(int sequenceLength, int sequence[5]) {
  for (int i=0; i < sequenceLength-1; i++) {
    //Play sequence item
    
    //Play folder sequence[i];

    //Wait till ready / delay Xms
  }
  //PlayLoop last item from sequence
  
  return true;
}


