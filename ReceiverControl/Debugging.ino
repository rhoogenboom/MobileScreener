void PrintReceiverInputValues() {
  Serial.println(F("------------"));
  for (int i=0; i<RC_CHANNEL_COUNT; ++i) {
    PrintChannel(i);
  }
  delay(1000);
}

void PrintChannel(int channel) {
  Serial.print(F("Channel "));Serial.print(channel+1);Serial.print(F(" - "));Serial.println(channel_pulse_time[channel]);
}

void PrintESCValue(int channel) {
  Serial.print(channelNames[channel]);
  Serial.print(F(" "));
  Serial.println(channel_pulse_time[channel]);
}

void PrintESCValues() {
  Serial.println(F("------------"));
  for (int i=0; i<RC_CHANNEL_COUNT; ++i) {
    PrintESCValue(i);
  }  
}

void PrintStates(){
  Serial.println(F("------------"));
  Serial.print(F("Crusher is moving: ")); Serial.println(ParseCrusherMovingState(crusherIsMoving));
  Serial.print(F("On/Off command: ")); Serial.println(ParseOnOffState(onOffCommand));
}

void PrintPulses(){
  Serial.println(F("------------"));
  Serial.print(F("Crusher pulse: ")); Serial.println(crusherPulse);
  Serial.print(F("Conveyor pulse: ")); Serial.println(beltPulse);
  Serial.print(F("Hopper pulse: ")); Serial.println(hopperPulse);
}

String ParseCrusherMovingState(bool state) {
  if (state) {
    return "TRUE";
  } else {
    return "FALSE";
  }
}

String ParseOnOffState(int state) {
  switch (state) {
    case POWER_IS_OFF :
      return "POWER_IS_OFF";
      break;
    case POWER_SWITCH_ON:
      return "POWER_SWITCH_ON";
      break;
    case POWER_IS_ON:
      return "POWER_IS_ON";
      break;
    case POWER_SWITCH_OFF:
      return "POWER_SWITCH_OFF";
      break;
    default:
      return "UNKNOWN STATE!";
  }
}

void PrintDebugOutput() {
  PrintReceiverInputValues();
  PrintESCValues();
  PrintStates();
  PrintPulses();
}

