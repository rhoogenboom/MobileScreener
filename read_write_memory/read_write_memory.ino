#include "defines.h"
#include "variables.h"
#include <EEPROM.h>


void setup() {

  long Temp;
  // Get EEPROM Initialization value
  eeprom_read(Temp, E_InitNum);

  // If EEPROM has never been initialized before, do so now
  if (Temp != EEPROM_Init)
  {
    Initialize_EEPROM();
  }
  else
  {
    Load_EEPROM();         // Otherwise, load the values from EEPROM
  }

}

void loop() {


}
