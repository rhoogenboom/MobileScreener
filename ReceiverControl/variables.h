bool startup = true; //indicate if we are still in startup mode for 


//RECEIVER 
volatile unsigned long timer_start[RC_CHANNEL_COUNT]; //start times for signal frequency 
volatile int channel_pulse_time[RC_CHANNEL_COUNT]; //keep track of the receiver values
int button_pressed_time[RC_CHANNEL_COUNT]; //keep track of how long the button was pressed
int button_pressed_value[RC_CHANNEL_COUNT]; //keep track of the button value
int channelPins[RC_CHANNEL_COUNT] = {5,6,7,8,9,12};

int CrusherCommand = 0;
int CrusherPulse = 0;
int CrusherButtonDown = 0;

int OnOffCommand = 0;
int OnOffPulse = 0;
int OnOffButtonDown = 0;

// SCREENER
ESC HopperESC (HOPPER_ESC_PIN, HOPPER_ESC_MIN, HOPPER_ESC_MAX, HOPPER_ESC_ARM);
ESC BeltESC (BELT_ESC_PIN, BELT_ESC_MIN, BELT_ESC_MAX, BELT_ESC_ARM);
ESC CrusherESC (CRUSHER_ESC_PIN, CRUSHER_ESC_MIN, CRUSHER_ESC_MAX, CRUSHER_ESC_ARM);


// AUDIO
bool engineIsRunningHigh = false;
bool engineIsRunning = false;

SoftwareSerial SerialMP3Player(PLAYER_RX_PIN, PLAYER_TX_PIN);

