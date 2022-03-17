#include <Arduino.h>

/* Defines of GPIO_Interrupt.ino */
const byte ledPin = 2;       // Builtin-LED pin
const byte interruptPin = 0; // BOOT/IO0 button pin
volatile byte state = LOW;

/* Defines of SendAndReceive.ino */
// select only NEC and the universal decoder for pulse width or pulse distance protocols
#define DECODE_NEC          // Includes Apple and Onkyo
#define DECODE_DISTANCE     // in case NEC is not received correctly

#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>
#define INFO
#define DELAY_AFTER_SEND 2000
#define DELAY_AFTER_LOOP 5000
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), IRsender, CHANGE);
}

void loop() {
  Serial.println("IR receiving...");
  /* Receiver code of SendAndReceive.ino */
}

void IRsender() {
  Serial.println("IR sending...");
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println(F("START " _FILE_ " from "_DATE_"\r\nUsing library version " VERSION_IRREMOTE));
  IrSender.begin();
  Serial.print(F("Ready to send IR signals at Pin"));
  Serial.println(IR_SEND_PIN);
  
  /* Sender of SendAndReceiv.ino */
}
