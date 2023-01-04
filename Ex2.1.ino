int greenLED = 2;
int yellowLED = 3;
int redLED = 4;

void setup() {
  Serial.begin(115200);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

}

void loop() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  delay(1000);

  goingGreen();
  delay(1000);
  goingRed();
  delay(1000);

}

void goingGreen() {
  digitalWrite(redLED, HIGH);
  delay(500);
  digitalWrite(yellowLED, HIGH);

  delay(500);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  Serial.println("GOOOO");

}

void goingRed() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(500);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  Serial.println("hold up");

}