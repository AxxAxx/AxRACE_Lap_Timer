#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
// constants won't change. They're used here to set pin numbers:
const int sensorPin = 13;     // the number of the pushbutton pin
const int ledPin =  2;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int sensorState = 0;         // variable for reading the pushbutton status

void setup() {
  SerialBT.begin("ESP32");
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
}

void loop() {
  // read the state of the pushbutton value:
  sensorState = digitalRead(sensorPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (sensorState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    SerialBT.println(1);
    delay(500);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
