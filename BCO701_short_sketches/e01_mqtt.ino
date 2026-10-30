#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* msg, unsigned int len) {
  if (msg[0] == '1') digitalWrite(2, HIGH);   // "1" = LED ON
  if (msg[0] == '0') digitalWrite(2, LOW);    // "0" = LED OFF
  Serial.println((char)msg[0]);
}

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  WiFi.begin("Your_SSID", "Your_PASSWORD");
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("WiFi connected");
  client.setServer("broker.hivemq.com", 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    client.connect("esp32_usn123");           // any unique name
    client.subscribe("iot/led");
    Serial.println("MQTT connected");
  }
  client.loop();
}
