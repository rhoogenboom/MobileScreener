//PINS
#define HOPPER_ESC_PIN (4) //nano: digital 2 
#define BELT_ESC_PIN (5) //nano: digital 3
#define CRUSHER_ESC_PIN (6) //nano: digital 4
#define HOPPER_RC_PIN (2) //nano: digital 5
#define BELT_RC_PIN (3) //nano: digital 6
#define CRUSHER_RC_PIN (18) //nano: digital 7
#define TRACK_LEFT_RC_PIN (19) //nano: digital 8
#define TRACK_RIGHT_RC_PIN (20) //nano: digital 9
#define ON_OFF_PIN (21) //nano: digital 12
#define PLAYER_BUSY_PIN (9) //notify when player is done playing and available, requires interrupt?? switch with on/off pin?
#define PLAYER_RX_PIN (10) //TX to player
#define PLAYER_TX_PIN (11) //RX from player


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

#define CRUSHER_CHANNEL (2) //array item number with value for on/off switch
#define CRUSHER_ESC_MIN (1000)
#define CRUSHER_ESC_MAX (2000)
#define CRUSHER_ESC_ARM (500) //brushless, probably a low arm value
#define CRUSHER_ESC_REVERSE (false)
#define CRUSHER_ESC_STOP (1500)
#define CRUSHER_ESC_LOW (150)
#define CRUSHER_ESC_MED (300)
#define CRUSHER_ESC_HIGH (500)

#define RC_CHANNEL_COUNT (6) //number of receiver channels hooked up to arduino
#define RC_CHANNEL_DEADBAND (5) //fluctuations around the channel center smaller than this we ignore

#define ON_OFF_CHANNEL (5) //array item number with value for on/off switch
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


//ENGINE
#define ENGINE_VERSION 2 //file version of the audio files, name starting with 000X

#define ENGINE_START_FOLDER 1 //folder number which contains these files 00X
#define ENGINE_LOW_FOLDER 2
#define ENGINE_UP_FOLDER 3
#define ENGINE_HIGH_FOLDER 4
#define ENGINE_DOWN_FOLDER 5
#define ENGINE_STOP_FOLDER 6


