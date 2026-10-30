void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);      // button
  pinMode(8, OUTPUT);     // relay IN
}

void loop() {
  int btn = digitalRead(2);
  digitalWrite(8, btn);   // pressed -> relay ON -> motor ON
  Serial.println(btn ? "Motor ON" : "Motor OFF");
  delay(500);
}
