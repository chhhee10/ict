#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin("Your_SSID", "Your_PASSWORD");
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("WiFi connected");
  ThingSpeak.begin(client);
}

void loop() {
  float temp = analogRead(A0) * 0.322;   // 330 / 1023 = 0.322
  Serial.println(temp);
  ThingSpeak.writeField(1234567, 1, temp, "YOUR_KEY");   // channel, field, value, key
  delay(20000);
}
