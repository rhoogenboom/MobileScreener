void StartEngine() {
  engineIsRunningHigh = false;
  engineIsRunning = true;
  
  //Play startup
  PlayFolderTrack(ENGINE_START_FOLDER, ENGINE_VERSION);

  //Wait till ready / delay Xms
  wait();

  //Start loop engine low
  RepeatPlaybackFolder(ENGINE_LOW_FOLDER);
}

void EngineUp() {
  //Play rev up
  PlayFolderTrack(ENGINE_UP_FOLDER, ENGINE_VERSION);
  //Wait till ready / delay Xms
  wait();
  
  //Start loop engine high
  RepeatPlaybackFolder(ENGINE_HIGH_FOLDER);
  engineIsRunningHigh = true;
}

void EngineDown() {
  //Play rev down
  PlayFolderTrack(ENGINE_DOWN_FOLDER, ENGINE_VERSION);
  
  //Wait till ready / delay Xms
  wait();
  
  //Start loop engine low
  RepeatPlaybackFolder(ENGINE_LOW_FOLDER);
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
  PlayFolderTrack(ENGINE_STOP_FOLDER, ENGINE_VERSION);
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


