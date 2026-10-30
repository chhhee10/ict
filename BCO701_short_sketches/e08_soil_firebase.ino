#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("Your_SSID", "Your_PASSWORD");
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("WiFi connected");
}

void loop() {
  int moisture = analogRead(A0);
  Serial.println(moisture);

  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;
  http.begin(client, "https://your-project-default-rtdb.firebaseio.com/moisture.json");
  Serial.println(http.PUT(String(moisture)));   // 200 = saved in Firebase
  http.end();
  delay(5000);
}
