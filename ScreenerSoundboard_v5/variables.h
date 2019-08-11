// EEPROM
const long EEPROM_Init = 0xA02; 

struct __eeprom_data { //  structure that maps all of the data we are storing in EEPROM
  long E_InitNum;      // Number that indicates if EEPROM values have ever been initialized
  byte E_volumeLevel;
};

bool startup = true; //indicate if we are still in startup mode for 

//RECEIVER 
volatile unsigned long timer_start[RC_CHANNEL_COUNT]; //start times for signal frequency 
volatile int channel_pulse_time[RC_CHANNEL_COUNT]; //keep track of the receiver values
int button_pressed_time[RC_CHANNEL_COUNT]; //keep track of how long the button was pressed
int button_pressed_value[RC_CHANNEL_COUNT]; //keep track of the button value
int channelPins[RC_CHANNEL_COUNT] = {2,3,18,19,20,12};
String channelNames[RC_CHANNEL_COUNT] = {"CRUSHER", "TRACK RAIL", "TRACK OTHER", "HOPPER", "BELT", "ON/OFF"};

//RC RECEIVER INPUT HANDLING
int onOffCommand = 0;
unsigned long onOffButtonDown = 0;
int crusherPulse = 0;
int onOffPulse = 0;
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
bool playerBusy = false;
byte volumeLevel;

//TIMER
OSL_SimpleTimer timer;  

//LIGHTS
bool lightsAreOn = false;
unsigned int redBlinkTimerID;
unsigned int greenBlinkTimerID;

bool greenLEDState = LOW;
bool redLEDState = LOW;

//BUTTONS
Button volumeUpButton(VOLUME_UP_PIN, 25, false, false);
Button volumeDownButton(VOLUME_DOWN_PIN, 25, false, false);
Button powerButton(POWER_ON_OFF_PIN, 25, false, false);
Button lightsButton(LIGHTS_ON_OFF_PIN, 25, false, false);
Button trackLeftForwardButton(TRACK_LEFT_FORWARD_PIN, 25, false, false);
Button trackLeftBackwardButton(TRACK_LEFT_BACKWARD_PIN, 25, false, false);
Button trackRightForwardButton(TRACK_RIGHT_FORWARD_PIN, 25, false, false);
Button trackRightBackwardButton(TRACK_RIGHT_BACKWARD_PIN, 25, false, false);

