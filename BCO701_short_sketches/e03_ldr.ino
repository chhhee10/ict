void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);
  if (light < 400) digitalWrite(13, HIGH);   // dark -> LED ON
  else digitalWrite(13, LOW);                // bright -> LED OFF
  delay(1000);
}
