#include <ESP8266WiFi.h>
#define BUILTIN_LED 2

//Network info - to be set by user
//ToDo - Set up "Set up via WiFi hotspot"
const char* ssid     = "Scorpio";
const char* password = "ROBISANOB";

//Host Info - To be set by user - DNS is Supported
const char* host = "m0zjo-HP-Compaq-6715b-GB835ET-ABU";
const int port = 8950;

String line;

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //Networking info
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(BUILTIN_LED, OUTPUT); 
}

int value = 0;

void loop() {
  delay(500);

  
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    return;
  }
  
  //Get Data Function will go here
  //GET DATA!!!!
  //Get Data end

  //Here the data will get packaged into the data string
  //PACKAGE DATA!!!
  //Package data end

  //Send data to server
  client.print(String("TEST_HEX_STRING") + millis());
  String req = client.readStringUntil(64); // Wait until '@' recieved
  Serial.println(req);
  Serial.println(req[0]);
  
  if (req[0] == 'L' && req[1] == 'E' && req[2] == 'D'){
    Serial.println("LED Change");
    bool val = (digitalRead(BUILTIN_LED));
    if (val == HIGH) {         // check if the input is HIGH (button released)
      digitalWrite(BUILTIN_LED, LOW);  // turn LED OFF
    } 
    
    else {
      digitalWrite(BUILTIN_LED, HIGH);  // turn LED ON
    }
  }
}

