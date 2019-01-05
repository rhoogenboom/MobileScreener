// EEPROM defines
#define eeprom_read_to(dst_p, eeprom_field, dst_size) eeprom_read_block(dst_p, (void *)offsetof(__eeprom_data, eeprom_field), MIN(dst_size, sizeof((__eeprom_data*)0)->eeprom_field))
#define eeprom_read(dst, eeprom_field) eeprom_read_to(&dst, eeprom_field, sizeof(dst))
#define eeprom_write_from(src_p, eeprom_field, src_size) eeprom_write_block(src_p, (void *)offsetof(__eeprom_data, eeprom_field), MIN(src_size, sizeof((__eeprom_data*)0)->eeprom_field))
#define eeprom_write(src, eeprom_field) { typeof(src) x = src; eeprom_write_from(&x, eeprom_field, sizeof(x)); }

// Useful functions
#define MIN(x,y) ( x > y ? y : x )
#define MAX(x,y) ( x > y ? x : y )

//PINS
#define CRUSHER_RC_PIN (2) 
#define TRACK_LEFT_RC_PIN (3) 
#define TRACK_RIGHT_RC_PIN (18)  
#define HOPPER_RC_PIN (19) 
#define BELT_RC_PIN (20)  
#define ON_OFF_RC_PIN (12) //nano: digital 12

#define CRUSHER_ESC_PIN (4)  
#define HOPPER_ESC_PIN (5) 
#define BELT_ESC_PIN (6)  

#define PLAYER_BUSY_PIN (21) //notify when player is done playing and available, requires interrupt?? switch with on/off pin?
#define PLAYER_RX_PIN (10) //connected to TX on player - 17-Serial2 RX
#define PLAYER_TX_PIN (11) //connected to RX on player - 16-Serial2 TX

//ARRAY NUMERING
#define CRUSHER_CHANNEL_NR (0) 
#define TRACK_LEFT_CHANNEL_NR (1) 
#define TRACK_RIGHT_CHANNEL_NR (2) 
#define HOPPER_CHANNEL_NR (3) 
#define BELT_CHANNEL_NR (4) 
#define ON_OFF_CHANNEL_NR (5) //array item number with value for on/off switch


#define HOPPER_ESC_MIN (1000) //minimal valid value for ESC
#define HOPPER_ESC_MAX (2000) //maximal valid value for ESC
#define HOPPER_ESC_ARM (1500) //centered value for ESC
#define HOPPER_ESC_REVERSE (false) //is this channel inverted (forward-back/back-forward)
#define HOPPER_ESC_STOP (1500) //value to send to stop the ESC
#define HOPPER_ESC_LOW (150) //value to send to run ESC at low rpm
#define HOPPER_ESC_MED (300) //value to send to run ESC at medium rpm
#define HOPPER_ESC_HIGH (500) //value to send to run ESC at high rpm

#define BELT_ESC_MIN (1000)
#define BELT_ESC_MAX (2000)
#define BELT_ESC_ARM (1500)
#define BELT_ESC_REVERSE (false)
#define BELT_ESC_STOP (1500)
#define BELT_ESC_LOW (150)
#define BELT_ESC_MED (300)
#define BELT_ESC_HIGH (500)

#define CRUSHER_ESC_MIN (1000)
#define CRUSHER_ESC_MAX (2000)
#define CRUSHER_ESC_ARM (1500) //brushless, probably a low arm value
#define CRUSHER_ESC_REVERSE (false)
#define CRUSHER_ESC_STOP (1500)
#define CRUSHER_ESC_LOW (150)
#define CRUSHER_ESC_MED (300)
#define CRUSHER_ESC_HIGH (500)

#define RC_CHANNEL_COUNT (6) //number of receiver channels hooked up to arduino
#define RC_CHANNEL_DEADBAND (40) //fluctuations around the channel center smaller than this we ignore
#define RC_CHANNEL_MIDDLE (1500) //fluctuations around the channel center smaller than this we ignore

#define ON_OFF_MIN (1000)
#define ON_OFF_MAX (2000)
#define CHANNEL_MIDDLE (1500)
#define ON_OFF_REVERSE (false)

#define POWER_IS_OFF (0) //power is off
#define POWER_SWITCH_ON (1) //power is switched on
#define POWER_IS_ON (2) //power is on
#define POWER_SWITCH_OFF (4) //power is switched off

#define CRUSHER_IS_OFF (0) //CRUSHER is off
#define CRUSHER_SWITCH_ON (1) //CRUSHER is switched on
#define CRUSHER_IS_ON (2) //CRUSHER is on
#define CRUSHER_SWITCH_OFF (4) //CRUSHER is switched off

#define BUTTON_PRESSED_SHORT (2000)
#define RECEIVER_CHANNEL_TIMEOUT (35000)

#define BAD_MIN_PULSE (500)
#define BAD_MAX_PULSE (2500)
#define ON_OFF_MIDDLE (1500)

#define quickBlinkSequence 5500

//LIGHTS
#define quickBlinkInterval 1000
#define slowBlinkInterval 750
#define fastBlinkInterval 100

#define WORKINGLIGHTS 34
#define GREEN_PIN 38
#define RED_PIN 42


