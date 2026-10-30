void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = analogRead(A0) * 0.488;   // 500 / 1024 = 0.488
  Serial.println(temp);
  delay(1000);
}
