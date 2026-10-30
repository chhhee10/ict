void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);    // Trig
  pinMode(10, INPUT);    // Echo
  pinMode(13, OUTPUT);   // LED / buzzer
}

void loop() {
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  int distance = pulseIn(10, HIGH) * 0.034 / 2;

  if (distance > 0 && distance < 20) {
    Serial.println("Intruder detected!");
    digitalWrite(13, HIGH);
  } else {
    Serial.println("Area clear");
    digitalWrite(13, LOW);
  }
  delay(500);
}
