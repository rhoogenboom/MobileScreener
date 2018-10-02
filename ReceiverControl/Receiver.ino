void HandleReceiverInput() {
//  for (int channel=0;channel <=5;channel++) {
//    channel_pulse_time[channel] = pulseIn(channelPins[channel], HIGH, RECEIVER_CHANNEL_TIMEOUT); 
//  }
  HandleOnOffChannel();
  HandleDriving();
  HandleBelt();
  HandleHopper();
  HandleCrusher();
}

void HandleCrusher(){
  CrusherPulse =  channel_pulse_time[CRUSHER_CHANNEL];

  if (CrusherPulse == 0) {
    //no receiver input or lost receiver input, maintain current values
  }
  else {
    //check if the pulse is considered a valid press
    if ((CrusherPulse >= ON_OFF_MIDDLE + RC_CHANNEL_DEADBAND) ||
        (CrusherPulse <= ON_OFF_MIDDLE - RC_CHANNEL_DEADBAND)) {
      //button is pressed enough left or right
      if (CrusherButtonDown > 0) {
        //if we had pressed before, check if we have pressed long enough to make a switch
        if ((CrusherButtonDown + BUTTON_PRESSED_SHORT >= millis()) && 
               CrusherCommand != CRUSHER_SWITCH_ON &&
                CrusherCommand != CRUSHER_SWITCH_OFF) {
                  //we pressed long enough and we have not started switching yet
          switch (CrusherCommand) {
            case CRUSHER_IS_OFF:
              CrusherCommand = CRUSHER_SWITCH_ON;
              break;
            case CRUSHER_IS_ON:
              CrusherCommand = CRUSHER_SWITCH_OFF;
              break;
          }
        }
      } else {
        //started pressing the button so take timing and state
        CrusherButtonDown = millis();
      }
    } else {
      // not pressing (anymore) 
      CrusherButtonDown = 0; //reset counter on button pressed

      //take action if we pressed long enough
      switch (CrusherCommand) {
        case CRUSHER_SWITCH_ON:
          CrusherCommand = CRUSHER_IS_ON;
          StartEngine();
          break;
        case CRUSHER_SWITCH_OFF:
          CrusherCommand = CRUSHER_IS_OFF;
          StopEngine();
          break;
      }
    }
  }
}

void HandleOnOffChannel() {
  OnOffPulse =  channel_pulse_time[ON_OFF_CHANNEL];

  if (OnOffPulse == 0) {
    //no receiver input or lost receiver input, maintain current values
  }
  else {
    //check if the pulse is considered a valid press
    if ((OnOffPulse >= ON_OFF_MIDDLE + RC_CHANNEL_DEADBAND) ||
        (OnOffPulse <= ON_OFF_MIDDLE - RC_CHANNEL_DEADBAND)) {
      //button is pressed enough left or right
      if (OnOffButtonDown > 0) {
        //if we had pressed before, check if we have pressed long enough to make a switch
        if ((OnOffButtonDown + BUTTON_PRESSED_SHORT >= millis()) && 
               OnOffCommand != POWER_SWITCH_ON &&
                OnOffCommand != POWER_SWITCH_OFF) {
                  //we pressed long enough and we have not started switching yet
          switch (OnOffCommand) {
            case POWER_IS_OFF:
              OnOffCommand = POWER_SWITCH_ON;
              break;
            case POWER_IS_ON:
              OnOffCommand = POWER_SWITCH_OFF;
              break;
          }
        }
      } else {
        //started pressing the button so take timing and state
        OnOffButtonDown = millis();
      }
    } else {
      // not pressing (anymore) 
      OnOffButtonDown = 0; //reset counter on button pressed

      //take action if we pressed long enough
      switch (OnOffCommand) {
        case POWER_SWITCH_ON:
          OnOffCommand = POWER_IS_ON;
          StartEngine();
          break;
        case POWER_SWITCH_OFF:
          OnOffCommand = POWER_IS_OFF;
          StopEngine();
          break;
      }
    }
  }
}

void HandleDriving() {

}

void HandleBelt() {

}

void HandleHopper() {

}

void calcSignal(int channel, int pinNumber)
{
  //if the pin has gone HIGH, record the microseconds since the Arduino started up
  if (digitalRead(pinNumber) == HIGH)
  {
    timer_start[channel] = micros();
  }
  //otherwise, the pin has gone LOW 
  else
  {
        //only worry about this if the timer has actually started
        if(timer_start[channel] != 0)
        { 
          //record the pulse time
          channel_pulse_time[channel] = ((volatile int)micros() - timer_start[channel]);
          timer_start[channel] = 0;
        }
  }
}

void calculateBeltReceiverInput() {
  calcSignal(0, BELT_RC_PIN);
}
void calculateHopperReceiverInput() {
  calcSignal(1, HOPPER_RC_PIN);
}
void calculateCrusherReceiverInput() {
  calcSignal(CRUSHER_CHANNEL, CRUSHER_RC_PIN);
}
void calculateTrackLeftReceiverInput() {
  calcSignal(3, TRACK_LEFT_RC_PIN);
}
void calculateTrackRightReceiverInput() {
  calcSignal(4, TRACK_RIGHT_RC_PIN);
}
void calculateOnOffReceiverInput() {
  calcSignal(ON_OFF_CHANNEL, ON_OFF_PIN);
}


