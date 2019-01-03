// EEPROM defines
#define eeprom_read_to(dst_p, eeprom_field, dst_size) eeprom_read_block(dst_p, (void *)offsetof(__eeprom_data, eeprom_field), MIN(dst_size, sizeof((__eeprom_data*)0)->eeprom_field))
#define eeprom_read(dst, eeprom_field) eeprom_read_to(&dst, eeprom_field, sizeof(dst))
#define eeprom_write_from(src_p, eeprom_field, src_size) eeprom_write_block(src_p, (void *)offsetof(__eeprom_data, eeprom_field), MIN(src_size, sizeof((__eeprom_data*)0)->eeprom_field))
#define eeprom_write(src, eeprom_field) { typeof(src) x = src; eeprom_write_from(&x, eeprom_field, sizeof(x)); }

// Useful functions
#define MIN(x,y) ( x > y ? y : x )
#define MAX(x,y) ( x > y ? x : y )

#define MIN_CHANNEL 875 //max left of RC controller
#define MAX_CHANNEL 2125 //max right of RC controller
#define CHANNEL_DEADCENTER 10

#define SERVO_MIN_POSITION 1000
#define SERVO_MAX_POSITION 1500
#define SERVO_MIDDLE_POSITION 1500

#define MIN_VALUE_MEASURED_FOR_POT 0
#define MAX_VALUE_MEASURED_FOR_POT 1024
#define CHANNEL_CENTER 512 //middle of pot meter

//setup pins and lights
#define SETUP_BUTTON A0
#define MAGNET_POT A5
#define SERVO_POT A6
#define MAGNET_LEFT_LED_RED 9
#define MAGNET_RIGHT_LED_GREEN 10

#define POWER_5V 2




