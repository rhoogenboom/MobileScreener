void StartEngine() {
  //Play startup

  //Wait till ready / delay Xms

  //Start loop engine low
}

void EngineUp() {
  //Play rev up

  //Wait till ready / delay Xms

  //Start loop engine high
}

void EngineDown() {
  //Play rev down

  //Wait till ready / delay Xms

  //Start loop engine low
}

void StopEngine() {
  //check if engine is high
    //EngineDown();
    
  //Play engine stop
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


