
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <NTPClient.h>
#include "DHT.h"

#include "index.h"

#define DHTTYPE DHT22
#define DHTPIN 12 

DHT dht(DHTPIN, DHTTYPE);

WebServer server(80);

float hum[144] = {0};
unsigned long actualTime = 0;
unsigned long rememberTime = 0;
unsigned long diffTime = 0;
int j = 0;

String times[144] = {"0"};

const char* ssid = "TP-Link_8748";
const char* password = "98517527";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

String formattedDate;

void handleRoot() {
 String s = MAIN_page; 
 server.send(200, "text/html", s); 
}
 
void handleADC() {
 float h = dht.readHumidity();
 String adcValue = String(h);
 
 server.send(200, "text/plain", adcValue); 
}

void handletable(){
  String str = "";
  for(int z = 0; z < 144; z++){
    str+= times[z]+" "+String(hum[z])+" ";
  }
  server.send(200, "text/plain", str); 
}

void handletime(){
  String tim = "";
  for(int z = 0; z < 144; z++){
    tim+= times[z]+" ";
  }
  server.send(200, "text/plain", tim); 
}

//===============================================================
// Setup
//===============================================================
void setup(void){
  for(int i = 0; i <144; i++) times[i] = "NULL";
  Serial.begin(115200);
  dht.begin();
  Serial.println();
  Serial.println("Booting Sketch...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  timeClient.begin();
  timeClient.setTimeOffset(7200);
  Serial.println("Connecting to ");
  Serial.print(ssid);

  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
    }
    
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", handleRoot);
  server.on("/readADC", handleADC);
  server.on("/readTAB", handletable);
 
  server.begin();
  Serial.println("HTTP server started");
}


void loop(void){
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }
  formattedDate = timeClient.getFormattedTime();
  server.handleClient();
  actualTime = millis();
  diffTime = actualTime - rememberTime;
  if(j > 143) j = 0;
  if(diffTime >= 600000UL){
    rememberTime= actualTime;
    hum[j] = dht.readHumidity();
    times[j] = formattedDate;
    j++;
  }
  delay(1);
}
