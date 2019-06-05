#include <WiFi.h>

//#define DEBUG

#ifdef DEBUG
  #define DEBUG_PRINT(x)  Serial.println (x)
#else
 #define DEBUG_PRINT(x)
#endif

// Replace with your network credentials
const char* ssid     = "AxRace_ESP32";
const char* password = "5555555555";

// Set web server port number to 80
WiFiServer server(80);

const int ledPin =  13;      // the number of the LED pin
const byte interruptPin = 34;


// How often to ping (milliseconds)
static const int PING_TIME = 5000;

// Special messages
static const String PING_MSG = "2";
static const String CONNECTED_MSG = "1";
static const String LAP_MSG = "0";

struct Button {
  bool pressed;
};

Button button1 = {false};

void IRAM_ATTR isr() {
  button1.pressed = true;
}

void blinklight(){
  for (int i = 0; i<5; i++){
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(150);
    }
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
  DEBUG_PRINT("Serup Complete")
  DEBUG_PRINT("AP IP address: " + IP)
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,
    blinklight();
    unsigned long senttime = millis();      // Last time a ping was sent
    client.println(CONNECTED_MSG);
    DEBUG_PRINT("New Client.");          // print a message out in the serial port
    while (client.connected()) {            // loop while the client's connected
      if (button1.pressed) {
        client.println(LAP_MSG);
        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);
        button1.pressed = false;    
      }
      unsigned long now = millis();
      if (now - senttime > PING_TIME) {
        client.println(PING_MSG);
        senttime = now;
      }
    }
  }
}
