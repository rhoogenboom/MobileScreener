void HandleReceiverInput() {
    
}

void calcSignal(int channel, int pinNumber) 
{
    //if the pin has gone HIGH, record the microseconds since the Arduino started up 
    if(digitalRead(pinNumber) == HIGH) 
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
            //restart the timer
            timer_start[channel] = 0;
        }
    } 
} 

void calculateBeltReceiverInput() { calcSignal(0, BELT_RC_PIN); }
void calculateHopperReceiverInput() { calcSignal(1, HOPPER_RC_PIN); }
void calculateCrusherReceiverInput() { calcSignal(2, CRUSHER_RC_PIN); }
void calculateTrackLeftReceiverInput() { calcSignal(3, TRACK_LEFT_RC_PIN); }
void calculateTrackRightReceiverInput() { calcSignal(4, TRACK_RIGHT_RC_PIN); }
void calculateOnOffReceiverInput() { calcSignal(5, TRACK_RIGHT_RC_PIN); }


