void Initialize_EEPROM()
{ // If EEPROM has not been used before, we initialize to some sensible, yet conservative, default values.
  // The first time a radio setup is performed, these will be overwritten with actual values, and never referred to agian.
  // Because the  radio setup is the first thing a user should do, these in fact should not come into play.
  int servoMinPulse = 1200;
  int servoMaxPulse = 1800;

  int potMiddlePosition = 514;
  int potMaxPositionLeft = 350;
  int potMaxPositionRight = potMiddlePosition + (potMiddlePosition - potMaxPositionLeft);

  eeprom_write(servoMinPulse, E_servoMinPulse);
  eeprom_write(servoMaxPulse, E_servoMaxPulse);
  eeprom_write(potMiddlePosition, E_potMiddlePosition);
  eeprom_write(potMaxPositionLeft, E_potMaxPositionLeft);

  // This is our initialization constant
  eeprom_write(EEPROM_Init, E_InitNum);

  // Finally - we still need to set up our variables, so now we call Load_EEPROM
  Load_EEPROM();
}

//load all our saved values at startup
void Load_EEPROM()
{
  eeprom_read(servoMinPulse, E_servoMinPulse);
  eeprom_read(servoMaxPulse, E_servoMaxPulse);
  eeprom_read(potMiddlePosition, E_potMiddlePosition);
  eeprom_read(potMaxPositionLeft, E_potMaxPositionLeft);

  potMaxPositionRight = potMiddlePosition + (potMiddlePosition - potMaxPositionLeft);
}

void Write_EEPROM() {
  eeprom_write(servoMinPulse, E_servoMinPulse);
  eeprom_write(servoMaxPulse, E_servoMaxPulse);
  eeprom_write(potMiddlePosition, E_potMiddlePosition);
  eeprom_write(potMaxPositionLeft, E_potMaxPositionLeft);

  // This is our initialization constant
  eeprom_write(1, E_InitNum);
}

