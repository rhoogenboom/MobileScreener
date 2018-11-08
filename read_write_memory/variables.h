// EEPROM
const long EEPROM_Init = 0xA01; // Change this any time the EEPROM content changes

struct __eeprom_data { // __eeprom_data is the structure that maps all of the data we are storing in EEPROM
  long E_InitNum;      // Number that indicates if EEPROM values have ever been initialized
  int E_servoMinPulse;
  int E_servoMaxPulse;
  int E_potMiddlePosition;
  int E_potMaxPositionLeft;
};

const int CHANNEL_CENTER = 511; //middle of RC controller 
const int CHANNEL_DEADCENTER = 10;
const int MIN_CHANNEL = 875; //max left of RC controller
const int MAX_CHANNEL = 2125; //max right of RC controller

const int minValueMeasuredForPot = 0;
const int maxValueMeasuredForPot = 1023;

int potMiddlePosition;// = 514; //overruled the middle position of maxValueMeasuredForPot divided by two 2 due to the magnetic center
int potMaxPositionLeft;// = 350; //minimale range potmeter movement left
int potMaxPositionRight;// = potMiddlePosition + (potMiddlePosition - potMaxPositionLeft); //maximal range potmeter movement right

//servo and steering variables
int servoMinPulse;
int servoMaxPulse;

