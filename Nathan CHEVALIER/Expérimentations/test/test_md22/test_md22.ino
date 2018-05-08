#include <Wire.h>

const int buttonPin = 2;
 int button =  0;

void setup()
{
 Wire.begin();  
  pinMode(buttonPin, INPUT);                      // connexion au bus I2c en tant que maître
}

void loop()
{
    button = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button == HIGH) {
     Wire.beginTransmission(0x58);          // adresse de la carte 0x58
     Wire.write(0x01);                        // registre vitesse moteur 1
     Wire.write(byte(255));                // valeur vitesse moteur 1,  0 ( maxi arrière)  128 (arrêt)  255 (maxi avant).
     Wire.endTransmission();
  }
  else{
    Wire.beginTransmission(0x58);          // adresse de la carte 0x58
     Wire.write(0x01);                        // registre vitesse moteur 1
     Wire.write(byte(126));                // valeur vitesse moteur 1,  0 ( maxi arrière)  128 (arrêt)  255 (maxi avant).
     Wire.endTransmission();
  }// arrêt transmission

}
