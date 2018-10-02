void PrintChannelValues() {
  Serial.println(F("------------"));
  for (int i=0; i<RC_CHANNEL_COUNT; ++i) {
    PrintChannel(i);
  }
  delay(50);
}

void PrintChannel(int channel) {
  Serial.print(F("Channel "));Serial.print(channel+1);Serial.print(F(" - "));Serial.println(channel_pulse_time[channel]);
}

