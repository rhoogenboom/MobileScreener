void HandleReceiverInput() {
  HandleOnOffChannel();
  HandleDriving();
  HandleBelt();
  HandleHopper();
  HandleCrusher();
}

void HandleCrusher(){
  crusherPulse =  channel_pulse_time[CRUSHER_CHANNEL_NR];

  if (crusherPulse == 0) {
    //no receiver input or lost receiver input, maintain current values
  }
  else {
//    //check if the pulse is considered a valid press
//    if (ChannelIsOffCenter(crusherPulse)) {
//      //button is pressed enough left or right
//      if (crusherButtonDown > 0) {
//        //if we had pressed before, check if we have pressed long enough to make a switch
//        if ((crusherButtonDown + BUTTON_PRESSED_SHORT >= millis()) && 
//               crusherCommand != CRUSHER_SWITCH_ON &&
//                crusherCommand != CRUSHER_SWITCH_OFF) {
//                  //we pressed long enough and we have not started switching yet
//          switch (CrusherCommand) {
//            case CRUSHER_IS_OFF:
//              crusherCommand = CRUSHER_SWITCH_ON;
//              break;
//            case CRUSHER_IS_ON:
//              crusherCommand = CRUSHER_SWITCH_OFF;
//              break;
//          }
//        }
//      } else {
//        //started pressing the button so take timing and state
//        crusherButtonDown = millis();
//      }
//    } else {
//      // not pressing (anymore) 
//      crusherButtonDown = 0; //reset counter on button pressed
//
//      //take action if we pressed long enough
//      switch (crusherCommand) {
//        case CRUSHER_SWITCH_ON:
//          crusherCommand = CRUSHER_IS_ON;
//          StartEngine();
//          break;
//        case CRUSHER_SWITCH_OFF:
//          crusherCommand = CRUSHER_IS_OFF;
//          StopEngine();
//          break;
//      }
//    }
    //set the output ESC channel
    CrusherESC.speed(crusherPulse);
  }
}

void HandleOnOffChannel() {
  onOffPulse =  channel_pulse_time[ON_OFF_CHANNEL_NR];

  if (onOffPulse == 0) {
    //no receiver input or lost receiver input, maintain current values
  }
  else {
    //check if the pulse is considered a valid press
    if (ChannelIsOffCenter(onOffPulse)) {
      //button is pressed enough left or right
      if (onOffButtonDown > 0) {
        //if we had pressed before, check if we have pressed long enough to make a switch
        if ((onOffButtonDown + BUTTON_PRESSED_SHORT >= millis()) && 
               onOffCommand != POWER_SWITCH_ON &&
                onOffCommand != POWER_SWITCH_OFF) {
                  //we pressed long enough and we have not started switching yet
          switch (onOffCommand) {
            case POWER_IS_OFF:
              onOffCommand = POWER_SWITCH_ON;
              break;
            case POWER_IS_ON:
              onOffCommand = POWER_SWITCH_OFF;
              break;
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
          StartEngine();
          break;
        case POWER_SWITCH_OFF:
          onOffCommand = POWER_IS_OFF;
          StopEngine();
          break;
      }
    }
  }
}

void HandleDriving() {
  int drivingPulseLeft =  channel_pulse_time[TRACK_LEFT_CHANNEL_NR];
  int drivingPulseRight =  channel_pulse_time[TRACK_RIGHT_CHANNEL_NR];

  if (drivingPulseLeft == 0 || drivingPulseRight == 0) {
    //no receiver input or lost receiver input, maintain current values
  }
  else {
    //check if the pulse is considered a valid press
    if ( ChannelIsOffCenter(drivingPulseLeft) || 
          ChannelIsOffCenter(drivingPulseRight) ) {
        //we have signal on the tracks so crusher is moving
        //TODO: play crusher moving warning signal
        crusherIsMoving = true;
      } 
      else {
        //TODO: stop playing crusher moving warning signal if we are playing something
        crusherIsMoving = false;
      }
  }
}

void HandleBelt() {
  beltPulse =  channel_pulse_time[BELT_CHANNEL_NR];

  if (beltPulse == 0) {
    //no receiver input or lost receiver input, maintain current values
  }
  else {

    BeltESC.speed(beltPulse);
  }
}

void HandleHopper() {
  hopperPulse =  channel_pulse_time[HOPPER_CHANNEL_NR];

  if (hopperPulse == 0) {
    //no receiver input or lost receiver input, maintain current values
  }
  else {

    HopperESC.speed(hopperPulse);
  }
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
  calcSignal(BELT_CHANNEL_NR, BELT_RC_PIN);
}
void calculateHopperReceiverInput() {
  calcSignal(HOPPER_CHANNEL_NR, HOPPER_RC_PIN);
}
void calculateCrusherReceiverInput() {
  calcSignal(CRUSHER_CHANNEL_NR, CRUSHER_RC_PIN);
}
void calculateTrackLeftReceiverInput() {
  calcSignal(TRACK_LEFT_CHANNEL_NR, TRACK_LEFT_RC_PIN);
}
void calculateTrackRightReceiverInput() {
  calcSignal(TRACK_RIGHT_CHANNEL_NR, TRACK_RIGHT_RC_PIN);
}
void calculateOnOffReceiverInput() {
  calcSignal(ON_OFF_CHANNEL_NR, ON_OFF_RC_PIN);
}

bool ChannelIsOffCenter(int channelValue) {
  return ((channelValue >= RC_CHANNEL_MIDDLE + RC_CHANNEL_DEADBAND) ||
        (channelValue <= RC_CHANNEL_MIDDLE - RC_CHANNEL_DEADBAND));
}

