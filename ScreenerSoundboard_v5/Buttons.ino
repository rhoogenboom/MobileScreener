void HandleVolumeButtons() {
    if (volumeUpButton.isPressed()) {
        ++volumeLevel;                            // increment the counter
        volumeLevel = min(volumeLevel, AUDIO_MAX_VOLUME);      // but not more than the specified maximum
        setVolume(volumeLevel);
        Serial.println(F("Increase volume"));
    }
    if (volumeDownButton.isPressed()) {
        --volumeLevel;                            // increment the counter
        volumeLevel = max(volumeLevel, AUDIO_MIN_VOLUME);      // but not more than the specified maximum
        setVolume(volumeLevel);
        Serial.println(F("Decrease volume"));
    }
}

void HandleOnOffButton() {
  if (powerButton.isPressed()) {
    Serial.println(F("Power button pressed"));
    if (engineIsRunning) {
      StopEngine();    
    } 
    else {
      StartEngine();
    }
  }
}

