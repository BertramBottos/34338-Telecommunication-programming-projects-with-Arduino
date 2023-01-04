int button = 7;
int greenLED = 2;

void setup() {
  Serial.begin(115200);
  pinMode(greenLED, OUTPUT);
  pinMode(button, INPUT_PULLUP);

}


void loop() {
  Serial.println(digitalRead(button));

  if (!digitalRead(button)) {
    digitalWrite(greenLED, !digitalRead(greenLED));
    while (!digitalRead(button)) {
    
    }
  }

}
