int buttonState = 0;

bool setupActive = false;

// EEPROM
const long EEPROM_Init = 0xA02; // Change this any time the EEPROM content changes

struct __eeprom_data { // __eeprom_data is the structure that maps all of the data we are storing in EEPROM
  long E_InitNum;      // Number that indicates if EEPROM values have ever been initialized
  int E_servoMinPulse;
  int E_potMaxPositionLeft;
};

int potMiddlePosition;// = 514; //overruled the middle position of maxValueMeasuredForPot divided by two 2 due to the magnetic center
int potMaxPositionLeft;// = 350; //minimale range potmeter movement left
int potMaxPositionRight;// = potMiddlePosition + (potMiddlePosition - potMaxPositionLeft); //maximal range potmeter movement right

//servo and steering variables
int servoMinPulse; //position should be stored in trailer EEPROM also
int servoMaxPulse; //position should be stored in trailer EEPROM also

