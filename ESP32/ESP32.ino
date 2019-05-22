#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
// constants won't change. They're used here to set pin numbers:
const int sensorPin = 13;     // the number of the pushbutton pin
const int ledPin =  2;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int sensorState = 0;         // variable for reading the pushbutton status

void IRAM_ATTR isr() {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    SerialBT.println(1);
    delay(1000);
    digitalWrite(ledPin, LOW);
}

void setup() {
  SerialBT.begin("ESP32");
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(sensorPin, INPUT_PULLUP);
  attachInterrupt(sensorPin, isr, FALLING);
}

void loop() { 
}
