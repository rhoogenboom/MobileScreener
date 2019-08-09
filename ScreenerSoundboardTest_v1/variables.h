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

int crusherPulse = 0;

int onOffCommand = 0;
int onOffPulse = 0;
unsigned long onOffButtonDown = 0;

int hopperPulse = 0;
int beltPulse = 0;

bool crusherIsMoving = false;



// AUDIO
bool engineIsRunningHigh = false;
bool engineIsRunning = false;
bool playerBusy = false;
byte volumeLevel;

//LIGHTS
OSL_SimpleTimer timer;  
unsigned int redBlinkTimerID;
unsigned int greenBlinkTimerID;

bool greenLEDState = LOW;
bool redLEDState = LOW;


