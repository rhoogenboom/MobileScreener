void StartEngine() {
  engineIsRunningHigh = false;
  engineIsRunning = true;
  
  //Play startup
  PlayFolderTrack(EngineStartFolder, EngineVersion);

  //Wait till ready / delay Xms
  wait();

  //Start loop engine low
  RepeatPlaybackFolder(EngineLowFolder);
}

void EngineUp() {
  //Play rev up
  PlayFolderTrack(EngineUpFolder, EngineVersion);
  //Wait till ready / delay Xms
  wait();
  
  //Start loop engine high
  RepeatPlaybackFolder(EngineHighFolder);
  engineIsRunningHigh = true;
}

void EngineDown() {
  //Play rev down
  PlayFolderTrack(EngineDownFolder, EngineVersion);
  
  //Wait till ready / delay Xms
  wait();
  
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
  wait();
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

