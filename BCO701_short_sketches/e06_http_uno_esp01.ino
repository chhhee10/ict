#include <SoftwareSerial.h>
SoftwareSerial esp(2, 3);   // RX, TX

void setup() {
  Serial.begin(9600);
  esp.begin(9600);
  esp.println("AT+CWMODE=1");
  delay(2000);
  esp.println("AT+CWJAP=\"Your_SSID\",\"Your_PASSWORD\"");
  delay(8000);
  esp.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  delay(3000);
  String req = "GET /update?api_key=YOUR_KEY&field1=45 HTTP/1.1\r\n";
  req += "Host: api.thingspeak.com\r\n\r\n";
  esp.print("AT+CIPSEND=");
  esp.println(req.length());
  delay(2000);
  esp.print(req);
}

void loop() {
  if (esp.available()) Serial.write(esp.read());      // show ESP replies
  if (Serial.available()) esp.write(Serial.read());   // type AT commands yourself
}
