void setup() {
  pinMode(4, INPUT);      // button
  pinMode(13, OUTPUT);    // LED
}

void loop() {
  digitalWrite(13, digitalRead(4));   // LED copies the button
}
