
int incomingByte = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I recceived: ");
    Serial.println(incomingByte, DEC);
    Serial.println((char)incomingByte);
  }
}