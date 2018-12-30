void PrintReceiverInputValues() {
  Serial.println(F("------------"));
  for (int i=0; i<RC_CHANNEL_COUNT; ++i) {
    PrintChannel(i);
  }
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
  Serial.print(F("Crusher is moving: ")); PrintTrueFalse(crusherIsMoving);
  Serial.print(F("On/Off command: ")); Serial.println(ParseOnOffState(onOffCommand));
}

void PrintPulses(){
  Serial.println(F("------------"));
  Serial.print(F("Crusher pulse: ")); Serial.print(crusherPulse); Serial.print(F("  mid:")); PrintTrueFalse(!ChannelIsOffCenter(crusherPulse));
  Serial.print(F("Conveyor pulse: ")); Serial.print(beltPulse); Serial.print(F("  mid:")); PrintTrueFalse(!ChannelIsOffCenter(beltPulse));
  Serial.print(F("Hopper pulse: ")); Serial.print(hopperPulse); Serial.print(F("  mid:")); PrintTrueFalse(!ChannelIsOffCenter(hopperPulse));
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

String PrintEngineState() {
  Serial.println(F("------------ENGINE"));
  Serial.print(F("Engine is running: ")); PrintTrueFalse(engineIsRunning);
  Serial.print(F("Engine is running high: ")); PrintTrueFalse(engineIsRunningHigh);
}

void PrintTrueFalse(boolean boolVal)
{
    if (boolVal == true) { Serial.println(F("TRUE")); } else { Serial.println(F("FALSE")); }
}

void PrintDebugOutput() {
  delay(1000);
//  PrintReceiverInputValues();
//  PrintESCValues();
  PrintStates();
  PrintPulses();
  PrintEngineState();
}

