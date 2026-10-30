#include <DHT.h>
DHT dht(7, DHT11);       // data pin, sensor type

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  Serial.print("Temp: ");
  Serial.print(dht.readTemperature());
  Serial.print("  Humidity: ");
  Serial.println(dht.readHumidity());
  delay(2000);
}
