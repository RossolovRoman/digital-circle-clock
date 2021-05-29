#include <Wire.h> 
#include <uRTCLib.h> //https://github.com/Naguissa/uRTCLib.git 
#include <SPI.h> 
#include <ClockLed.h>

//DS3231
#define SPI_ADDRESS_DS3231 0x68

uRTCLib rtc(SPI_ADDRESS_DS3231, 2);
ClockLed clockLed = ClockLed();

uint32_t targetTime = 0;                  
uint32_t timeHour, timeMinute, timeSecond;
uint32_t dateDay, dateMonth, dateYear;
uint32_t dayOfWeek;
double temp;
 
void setup(void) { 
  Serial.begin(115200);
  Wire.begin();

  clockLed.init();

  // RTCLib :: set (byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year) 
  //rtc.set(0, 35, 8, 3, 25, 5, 21); 

  clockLed.check();

  rtc.refresh();

	//rtc.lostPowerClear();
  targetTime = millis() + 1000; 
}
 
void loop()  { 
  rtc.refresh();
  if (targetTime < millis()) {
 
    timeHour = rtc.hour();
    timeMinute = rtc.minute();
    timeSecond = rtc.second();
    dateDay = rtc.day();
    dateMonth = rtc.month();
    dateYear = rtc.year();
    dayOfWeek = rtc.dayOfWeek();
    temp = rtc.temp()/100.0;
    
    targetTime = millis() + 1000;
    Serial.print(timeHour);
    Serial.print(":");
    Serial.print(timeMinute);
    Serial.print(":");
    Serial.print(timeSecond);
    Serial.print("   ");
    Serial.print(dateDay);
    Serial.print(".");
    Serial.print(dateMonth);
    Serial.print(".");
    Serial.print(dateYear);
    Serial.print("    ");
    Serial.print(dayOfWeek);
    Serial.print("    ");
    Serial.print(temp);
    Serial.println("");
  }
}
