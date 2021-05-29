#if defined(ARDUINO) && ARDUINO >= 100  // Arduino IDE Version
#include "Arduino.h"
#else
#include <WProgram.h>
#endif

#include "ClockLed.h"

// Private Methods //////////////////////////////////////////////////////////////

// void ClockLed::show(){
//     for(int lamps = 0; lamps<NUM_LEDS/COUNT_LEDS_HEADLIGHT; lamps++)
//     {
//         for(int led = 0; led<COUNT_LEDS_HEADLIGHT; led++){
//             _strip.setPixelColor(_leds[lamps][led], _leds_color[lamps][led]);
//         }
//     }
//     _strip.show();
// }

// Public Methods //////////////////////////////////////////////////////////////

ClockLed::ClockLed()
{   
    _red_low = _strip.Color(70, 0, 0);
    _white_low = _strip.Color(70, 70, 70);
    _black = _strip.Color(0, 0, 0);
}

void ClockLed::indicationClock(uint32_t *hour, uint32_t *minute, uint32_t *seconds)
{

}

void ClockLed::init()
{
    _strip.begin();     // Sets up the SPI
    _strip.show();      // Clears the strip, as by default the strip data is set to all LED's off.
    //_strip.setBrightness(0);
}

void ClockLed::check()
{
    for(int led = 0; led < 16; led++){
        delay(100);
        _strip.setPixelColor(led, _red_low);
        _strip.show();
    }
    for(int led = 0; led < 16; led++){
        delay(100);
        _strip.setPixelColor(led, _black);
        _strip.show();
    }
}
