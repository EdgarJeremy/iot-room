#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>

const char* ssid = "teraskopi";
const char* password = "teraskopi221b";
const char* url = "http://192.168.1.9/update?data=";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected");
}

void loop() {
  String data = Serial.readStringUntil('\n');
  Serial.println(data.length());
  if(WiFi.status() == WL_CONNECTED && data.length() > 0) {
    HTTPClient http;
    http.begin(url + data);
    int httpCode = http.GET();
    if(httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    }
    http.end();
  }
}
