void Initialize_EEPROM() { // If EEPROM has not been used before, we initialize to some sensible, yet conservative, default values.
  byte volumeLevel = 20;

  eeprom_write(volumeLevel, E_volumeLevel);

 // This is our initialization constant
  eeprom_write(EEPROM_Init, E_InitNum);

  // Finally - we still need to set up our variables, so now we call Load_EEPROM
  Load_EEPROM();
}

//load all our saved values at startup
void Load_EEPROM() {
  eeprom_read(volumeLevel, E_volumeLevel);

  Serial.print("Volume retrieved: "); Serial.println(volumeLevel);
}

void Write_EEPROM() {
  // This is our initialization constant
  eeprom_write(1, E_InitNum);
  eeprom_write(volumeLevel, E_volumeLevel);

  Serial.print("Volume stored: "); Serial.println(volumeLevel);
}
