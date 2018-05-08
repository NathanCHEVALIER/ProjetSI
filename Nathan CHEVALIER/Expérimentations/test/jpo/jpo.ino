#include <Wire.h>
#include "rgb_lcd.h"
//#include <Digital_Light_TSL2561.h>
#include "Ultrasonic.h"

rgb_lcd lcd;
Ultrasonic ultrasonic(7);
//RGB sur port I2C
//1 Ultrasons sur D7
//2 Ultrason sur D8
//Photorésistance sur D2
float Rsensor;
long distance;
long luminosite;
int porte = 0;//porte abaissée
int nombre = 0;//nombre de passages
int precedent = 0;//etat precedent capteur ultrason

void setup()
{
    Wire.begin();
    lcd.begin(16, 2);
    Serial.begin(9600);
    //TSL2561.init();
}

void loop()
{  
    distance = ultrasonic.MeasureInCentimeters();
    //luminosite = TSL2561.readVisibleLux();

    //On détecte un changements par rapport à la distance initiale
    if(distance < 38)
    {
        if(precedent == 0){
            nombre += 1;
        }
        precedent = 1;
        lcd.setRGB(255, 0, 0);        
    }
    else{
        precedent = 0;
        lcd.setRGB(6, 247, 238);
    }
    //On détecte la nuit
    /*if(luminosite < 200)
    {
        if(porte == 0){
            //abaisser la porte
        }
        porte = 1;      
    }
    else{
        porte = 0;
    }*/
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(distance);
    lcd.setCursor(3,0);
    lcd.print("cm -");
    lcd.setCursor(8,0);
    lcd.print(nombre);
    lcd.setCursor(10,0);
    lcd.print("Poules");
    lcd.setCursor(0,1);
    //lcd.print(luminosite);
    lcd.setCursor(10,1);
    if(porte == 1){
        lcd.print("Ouvert");
    }
    else{
        lcd.print("Ferme");
    }

    delay(100);
}

