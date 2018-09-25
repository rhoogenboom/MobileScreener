void PrintChannelValues() {
  Serial.println(F("------------"));
  for (int i=0;i++;i<RC_CHANNEL_COUNT) {
    PrintChannel(i);
  }
  Serial.println();
}

void PrintChannel(int channel) {
  Serial.print(F("Channel "));//Serial.print(channel);Serial.print(F(" - "));Serial.println(channel_pulse_time[channel+1]);
}

