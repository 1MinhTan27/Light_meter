#ifndef _DEFINE_H
#define _DEFINE_H
#include <Arduino.h>

#define cDebug                          (0)
#define cMainDebug                      (0)
#define cSensorDebug                    (0)
#define cButtonDebug                    (0)
#define cDisplayDebug                   (0)

#define DEBUG_COM Serial
#define HEADER_FORMAT(fmt) "<%s>:<%d> " fmt "\r\n", pathToFileName(__FILE__), __LINE__
#define dbg_main(format, ...) (cMainDebug&cDebug) ? DEBUG_COM.printf(HEADER_FORMAT(format), ##__VA_ARGS__) : NULL
#define dbg_sensor(format, ...) (cSensorDebug&cDebug) ? DEBUG_COM.printf(HEADER_FORMAT(format), ##__VA_ARGS__) : NULL
#define dbg_button(format, ...) (cButtonDebug&cDebug) ? DEBUG_COM.printf(HEADER_FORMAT(format), ##__VA_ARGS__) : NULL
#define dbg_display(format, ...) (cDisplayDebug&cDebug) ? DEBUG_COM.printf(HEADER_FORMAT(format), ##__VA_ARGS__) : NULL

#define TFT_SCK    18
#define TFT_MOSI   23
#define TFT_MISO   19
#define TFT_CS     22
#define TFT_DC     21
#define TFT_RESET  17

// #define PIN_Sensor1 36
// #define PIN_Sensor2 34
// #define PIN_Sensor3 35
// #define PIN_Sensor4 32
// #define PIN_Sensor5 33

#define ON_LED      25

#define valueMAXsensor  9000
#define NumberButton    3
#define TimePressAnti  50
#define calibTime       5000
#define BUTTON_RED      13
#define BUTTON_BLUE     16
#define BUTTON_WHITE    4  

#define numberCalibration 300




#endif
