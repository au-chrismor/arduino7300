// Controller for LPF and LDMOS amplifier
// Christopher F. Moran, VK2MEI
//

#ifndef __ARDUINO7300_H_INC__

#include <thermistor.h>
#include <LiquidCrystal_I2C.h>

#define RLY_10M        D2
#define RLY_15M        D3
#define RLY_30M        D6
#define RLY_40M        D6
#define RLY_80M        D8
#define TX_PIN         D9
#define SDA_PIN        D4
#define SCL_PIN        D5

#define BAND_IN        A0
#define THERM_PIN      A1
#define CURRENT_PIN    A2

#define LCD_ROWS       4
#define LCD_COLS       20
#define LCD_ADDR       0x3F

#define THERM_RES      10000
#define THERM_BETA     3950
#define THERM_SERIES   9980

#define NUM_SAMPLES   3

#define __ARDUINO7300_H_INC__
#endif
