#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

void setup() {
  Serial.begin(115200);
  pinMode(D5, OUTPUT);   // Trig
  pinMode(D6, INPUT);    // Echo
  WiFi.begin("Your_SSID", "Your_PASSWORD");
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("WiFi connected");
}

void loop() {
  digitalWrite(D5, HIGH);
  delayMicroseconds(10);
  digitalWrite(D5, LOW);
  int distance = pulseIn(D6, HIGH) * 0.034 / 2;
  Serial.println(distance);

  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;
  http.begin(client, "https://your-project-default-rtdb.firebaseio.com/distance.json");
  Serial.println(http.PUT(String(distance)));   // 200 = saved
  http.end();
  delay(5000);
}
