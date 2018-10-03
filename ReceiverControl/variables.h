bool startup = true; //indicate if we are still in startup mode for 


//RECEIVER 
volatile unsigned long timer_start[RC_CHANNEL_COUNT]; //start times for signal frequency 
volatile int channel_pulse_time[RC_CHANNEL_COUNT]; //keep track of the receiver values
int button_pressed_time[RC_CHANNEL_COUNT]; //keep track of how long the button was pressed
int button_pressed_value[RC_CHANNEL_COUNT]; //keep track of the button value
int channelPins[RC_CHANNEL_COUNT] = {2,3,18,19,20,21};
String channelNames[RC_CHANNEL_COUNT] = {"CRUSHER", "TRACK RAIL", "TRACK OTHER", "HOPPER", "BELT", "ON/OFF"};

int crusherCommand = 0;
int crusherPulse = 0;
int crusherButtonDown = 0;

int onOffCommand = 0;
int onOffPulse = 0;
int onOffButtonDown = 0;

int hopperPulse = 0;
int beltPulse = 0;

bool crusherIsMoving = false;

// SCREENER
ESC HopperESC (HOPPER_ESC_PIN, HOPPER_ESC_MIN, HOPPER_ESC_MAX, HOPPER_ESC_ARM);
ESC BeltESC (BELT_ESC_PIN, BELT_ESC_MIN, BELT_ESC_MAX, BELT_ESC_ARM);
ESC CrusherESC (CRUSHER_ESC_PIN, CRUSHER_ESC_MIN, CRUSHER_ESC_MAX, CRUSHER_ESC_ARM);


// AUDIO
bool engineIsRunningHigh = false;
bool engineIsRunning = false;

//SoftwareSerial SerialMP3Player(PLAYER_RX_PIN, PLAYER_TX_PIN);

