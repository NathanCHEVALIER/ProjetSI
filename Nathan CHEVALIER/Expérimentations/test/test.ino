#include <Wire.h>
#include "rgb_lcd.h"
#include "Ultrasonic.h"

rgb_lcd lcd;
Ultrasonic ultrasonic(7);

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setRGB(0, 255, 0);
}

void loop()
{
    long distance;

    distance = ultrasonic.MeasureInCentimeters();
    Serial.print(distance);
    Serial.println(" cm");
    
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.setRGB(0,0,255);
    lcd.print(distance);
    
    delay(200);
}

