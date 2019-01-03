void HandleReceiverInput() {
  HandleOnOffChannel();
  delay(500);
}



void HandleOnOffChannel() {
  onOffPulse =  pulseIn(ON_OFF_RC_PIN, HIGH);

  if (onOffPulse == 0) {
    //no receiver input or lost receiver input, maintain current values
    Serial.println("no receiver input or lost receiver input, maintain current values");
  }
  else {
    channel_pulse_time[ON_OFF_CHANNEL_NR] = onOffPulse;
    //check if the pulse is considered a valid press
    if (ChannelIsOffCenter(onOffPulse)) {
      //button is pressed enough left or right
      Serial.println("button is pressed left or right");
      if (onOffButtonDown != 0) {
        //if we had pressed before, check if we have pressed long enough to make a switch
        Serial.print("Millis: "); Serial.print(millis()); Serial.print("   button down + press time: "); Serial.println(onOffButtonDown + BUTTON_PRESSED_SHORT);
        if (onOffButtonDown + BUTTON_PRESSED_SHORT <= millis()) {
          //we pressed long enough 
          Serial.println("we pressed long enough");

          if (isButtonOn(onOffPulse)) {
            onOffCommand = POWER_SWITCH_ON; 
          } 
          else {
            onOffCommand = POWER_SWITCH_OFF;
          }
        }
      } else {
        //started pressing the button so take timing and state
        onOffButtonDown = millis();
      }
    } else {
      // not pressing (anymore) 
      onOffButtonDown = 0; //reset counter on button pressed

      //take action if we pressed long enough
      switch (onOffCommand) {
        case POWER_SWITCH_ON:
          onOffCommand = POWER_IS_ON;
          engineIsRunning = true;
        //  StartEngine();
          break;
        case POWER_SWITCH_OFF:
          onOffCommand = POWER_IS_OFF;
          engineIsRunning = false;
        //  StopEngine();
          break;
      }
    }
  }
}

bool isButtonOn(int channelValue) {
  return (channelValue >= (RC_CHANNEL_MIDDLE + RC_CHANNEL_DEADBAND));
}

bool isButtonOff(int channelValue) {
  return (channelValue <= (RC_CHANNEL_MIDDLE + RC_CHANNEL_DEADBAND));
}

bool ChannelIsOffCenter(int channelValue) {
  return ((channelValue >= RC_CHANNEL_MIDDLE + RC_CHANNEL_DEADBAND) ||
        (channelValue <= RC_CHANNEL_MIDDLE - RC_CHANNEL_DEADBAND));
}


