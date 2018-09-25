bool startup = false; //indicate if we are still in startup mode for 


//RECEIVER 
volatile unsigned long timer_start[RC_CHANNEL_COUNT]; //start times for signal frequency 
volatile int channel_pulse_time[RC_CHANNEL_COUNT]; //keep track of the receiver values


// SCREENER
ESC HopperESC (HOPPER_ESC_PIN, HOPPER_ESC_LOW, HOPPER_ESC_HIGH, HOPPER_ESC_ARM);
ESC BeltESC (BELT_ESC_PIN, BELT_ESC_LOW, BELT_ESC_HIGH, BELT_ESC_ARM);
ESC CrusherESC (CRUSHER_ESC_PIN, CRUSHER_ESC_LOW, CRUSHER_ESC_HIGH, CRUSHER_ESC_ARM);


// AUDIO
bool engineIsRunningHigh = false;
bool engineIsRunning = false;

