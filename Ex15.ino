#include <ESP8266WiFi.h>
#include <ThingSpeak.h>


const char* ssid = "Bertrams iPhone 6";
const char* pass = "Hemmeligt";
int X = 1;
int Y = 2;


WiFiClient client;

unsigned long channelID = 2003172;  //your TS channal
const char* APIKey = "4YE14ZT1RTHCHDNJ";   //your TS API
const char* server = "api.thingspeak.com";
const int postDelay = 20 * 1000;  //post data every 20 seconds 

void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT);
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {  // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i);
    Serial.print(' ');
  }
  Serial.println();
}

bool data1;  //measured data
float data2;

void loop() {

  data1 = digitalRead(4);
  data2 = WiFi.RSSI();

  ThingSpeak.begin(client);
  client.connect(server, 80);    //connect(URL, Port)
  ThingSpeak.setField(X, data1);  //set data on the X graph
  ThingSpeak.setField(Y, data2);
  ThingSpeak.writeFields(channelID, APIKey);  //post everything to TS
  client.stop();
  delay(postDelay);  //wait and then post again
}


