#include <Wire.h>
#include "rgb_lcd.h"
//#include <Digital_Light_TSL2561.h>
#include "Ultrasonic.h"

rgb_lcd lcd;
Ultrasonic ultrasonic(7);
Ultrasonic ultrasonic2(8);
//RGB sur port I2C
//1 Ultrasons sur D7
//2 Ultrason sur D8
//Photorésistance sur D2
float Rsensor;
long distance1;
long distance2;
int distances1[] = {0};
int distances2[] = {0};
int newcase;

void setup()
{
    Wire.begin();
    lcd.begin(16, 2);
    lcd.setRGB(6, 247, 238);
    Serial.begin(9600);
    //TSL2561.init();
}

void loop()
{  
    distance1 = ultrasonic.MeasureInCentimeters();
    delay(10);
    distance2 = ultrasonic2.MeasureInCentimeters();

    //On détecte un changements par rapport à la distance initiale
    if(distance1 < 40 || distance2 < 40)
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(distance1);
        lcd.setCursor(0,1);
        lcd.print(distance2);
        newcase = sizeof(distance1);
        Serial.print('Nouvelle case: ');
        Serial.print(newcase);
        Serial.print('\n');
        distances1[newcase + 1] = distance1;
        for(int i = 0; i <= sizeof(distances1); i++)
        {
            Serial.print(distances1[i]);
            Serial.print('-');
        }
    }
    else
    {
        lcd.clear();
    }

  //TSL2561.readVisibleLux()

    Serial.print(sizeof(distances1));
    Serial.print('\n');

    delay(100);
}

