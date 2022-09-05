#include <HCSR04.h>
#include <DS3231.h>
#include <Wire.h>


HCSR04 hc(5, 6); //initialisation class HCSR04 (trig pin , echo pin)
RTClib myRTC;


void setup()
{ 
  Serial.begin(57600);
  Wire.begin();
    delay(500);
  }

void loop()
{
  if (hc.dist() < 60){
    DateTime now = myRTC.now();
     Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    }
//    Serial.println( hc.dist()); //return current distance (cm) in serial
    delay(60);                   // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
}
