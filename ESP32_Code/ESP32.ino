#include <WiFi.h>

#define WIFI
#define DEBUG

// Replace with your network credentials
const char* ssid     = "ESP32-Access-Point";
const char* password = "5555555555";

// Set web server port number to 80
WiFiServer server(80);

const int ledPin =  2;      // the number of the LED pin
const byte interruptPin = 13;
Button button1 = {false};


// How often to ping (milliseconds)
static const int PING_TIME = 1000;

// Special messages
static const String PING_MSG = "SOCKET_PING";
static const String CONNECTED_MSG = "SOCKET_CONNECTED";

struct Button {
  bool pressed;
};

void IRAM_ATTR isr() {
  button1.pressed = true;
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin,INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), isr, FALLING);

  WiFi.disconnect();
  delay(200); //this delay, if you comment out it all works, if left, softAPIP returns 0.0.0.0
  WiFi.mode(WIFI_STA);
  WiFi.begin("", "");
  int connRes = WiFi.waitForConnectResult();
  WiFi.mode(WIFI_AP);
  //assuming connecting failed
  WiFi.softAP(ssid, NULL);//, password);  
  delay(500); 
  server.begin();

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,

    int senttime = millis();      // Last time a ping was sent
    client.println(CONNECTED_MSG);
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (button1.pressed) {
        client.println("1");
        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);
        button1.pressed = false;    
      }
      int now = millis();
      if (now - senttime > PING_TIME) {
        client.println(PING_MSG);
        senttime = now;
      }
    }
  }
}
