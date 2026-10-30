void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);    // IN1
  pinMode(9, OUTPUT);    // IN2
}

void loop() {
  digitalWrite(8, HIGH); digitalWrite(9, LOW);
  Serial.println("Clockwise");
  delay(2000);

  digitalWrite(8, LOW);  digitalWrite(9, LOW);
  Serial.println("Stop");
  delay(1000);

  digitalWrite(8, LOW);  digitalWrite(9, HIGH);
  Serial.println("Anticlockwise");
  delay(2000);

  digitalWrite(8, LOW);  digitalWrite(9, LOW);
  Serial.println("Stop");
  delay(1000);
}
