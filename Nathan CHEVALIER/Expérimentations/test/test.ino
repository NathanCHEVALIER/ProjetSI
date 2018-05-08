#include <Wire.h>
#include "rgb_lcd.h"
#include <Digital_Light_TSL2561.h>
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
int* distances1 = malloc(sizeof(int));
int distances2 = 0;
int newcase;
int nbcases = 0;

void setup()
{
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setRGB(6, 247, 238);
  Serial.begin(9600);
  TSL2561.init();
}

void loop()
{
  distance1 = ultrasonic.MeasureInCentimeters();
  delay(10);
  distance2 = ultrasonic2.MeasureInCentimeters();

  //On détecte un changements par rapport à la distance initiale
  if (distance1 < 28 /*|| distance2 < 28*/)
  {
    //Inscription sur afficheur
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(distance1);
    lcd.setCursor(0, 1);
    lcd.print(distance2);
    //enregsitrement données tableau
    /*nbcases += 1;
    distances1 = realloc(distances1, nbcases * sizeof(int));
    distances1[nbcases] = distance1;

    for (int i = 0; i <= nbcases; i++)
    {
      Serial.print(distances1[i]);
      Serial.print('-');
    }
    Serial.print('\n');*/
  }
  else
  {
    lcd.clear();
  }

  //Rsensor = TSL2561.readVisibleLux();
  lcd.setCursor(10, 0);
  //lcd.print(Rsensor);

  delay(100);
}

