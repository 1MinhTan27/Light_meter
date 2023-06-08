#ifndef _DISPLAY_LCD_H
#define _DISPLAY_LCD_H
#include "Arduino.h"
#include "U8g2lib.h"
#include "Arduino_GFX_Library.h"

typedef enum
{
    escreenStart,
    ewaitingReadsensor,
    eprepare,
    escreenResult,
    escreenAverageResult,
    ecalibSensor
} e_statuslcd;

class displayCLD
{
private:
    /* data */
    Arduino_ESP32SPI *bus;
    Arduino_GFX *display; // Arduino_ILI9341

public:
    displayCLD(/* args */);
    ~displayCLD();

    void begin();
    void logoFortebiotech();
    void screen_Start();
    void screen_Complete();
    void screen_Result();
    void screen_Average_Result();
    void read_screen(int step_);
    void waiting_Readsensor();
    void prepare();
    void screen_Calib();
    void waiting_Calib();
    void screen_Calib_Complete();
    void loop();

    e_statuslcd type_infor = escreenStart;
    uint8_t couter = 0;
    uint8_t instantStatus[2];
    bool changeScreen = true;
    // void screen2();
    // void screen3();
};

extern displayCLD _displayCLD;

#endif
