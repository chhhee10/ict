#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("Your_SSID", "Your_PASSWORD");
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("WiFi connected");
}

void loop() {
  WiFiClient client;
  HTTPClient http;
  http.begin(client, "http://api.thingspeak.com/update?api_key=YOUR_KEY&field1=45");
  int code = http.GET();                 // SEND
  Serial.println(code);                  // 200 = OK
  Serial.println(http.getString());      // RECEIVE (entry number)
  http.end();
  delay(20000);
}
