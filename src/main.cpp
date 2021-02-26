#include <Arduino.h>

#define PIN_LED_ROUGE 3 
#define DEMI_PERIODE_ROUGE 150000 
#define PIN_LED_VERTE 5
#define DEMI_PERIODE_VERTE 260000
#define basculeLED(x) digitalWrite(x, !digitalRead(x)) 

void setup() {
  // Configure les broches des LEDs en sortie
  pinMode(PIN_LED_ROUGE, OUTPUT);
  pinMode(PIN_LED_VERTE, OUTPUT); 
} 

void loop() { 
  static unsigned long dernierRouge = 0, dernierVerte = 0;
  if ((micros() - dernierRouge) >= DEMI_PERIODE_ROUGE) { 
    dernierRouge = dernierRouge + DEMI_PERIODE_ROUGE;
    /*if (digitalRead(PIN_LED_ROUGE) == HIGH) digitalWrite(PIN_LED_ROUGE, LOW); else digitalWrite(PIN_LED_ROUGE, HIGH);*/
    /*digitalWrite(PIN_LED_ROUGE, !digitalRead(PIN_LED_ROUGE));*/
    basculeLED(PIN_LED_ROUGE);
  } 
  if ((micros() - dernierVerte) >= DEMI_PERIODE_VERTE) {
    dernierVerte = dernierVerte + DEMI_PERIODE_VERTE; basculeLED(PIN_LED_VERTE);
  }
}