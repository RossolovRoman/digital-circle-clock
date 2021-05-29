#ifndef ClockLed_h
#define ClockLed_h
#include <WS2812B.h>

#define COUNT_LEDS 16
#define NUM_LEDS 12
#define NUM_LEDS 60

//#define PIN_LEDS    PA7     //Library uses SPI1. Connect the WS2812B data input to MOSI on your board. (STM32: PA7)

class ClockLed {
public:
    ClockLed();
    void indicationClock(uint32_t *hour, uint32_t *minute, uint32_t *seconds);
    void init();
    void check();
    
private:
    // int _leds[2][NUM_LEDS] = {{0, 2, 3, 4, 6, 7, 8, 10, 11, 12, 14, 15},
    //                         {1, 0, 0, 1, 0, 0, 1, 0,  0,  1,  0,  0 }};

    WS2812B _strip = WS2812B(COUNT_LEDS);

    uint32_t _black;
    uint32_t _red_low;
    uint32_t _white_low;

    bool _flasher_status = false;
};

#endif
