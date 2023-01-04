int redPIN = 3;
int greenPIN = 5;
int bluePIN = 6;
int potPIN = A5;

signed int HUE[3] = {0,0,0};
int potVal = 0;

void setup() {
  pinMode(redPIN, OUTPUT);
  pinMode(greenPIN, OUTPUT);
  pinMode(bluePIN, OUTPUT);
  pinMode(potPIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPIN);

  if (potVal < 512) {
    HUE[1] = 0.4985 * potVal;
    HUE[2] = 0.4985 * (512-potVal);
    HUE[0] = 0;
  }
  else {
    HUE[1] = 0.4985 * (1023-potVal);
    HUE[2] = 0;
    HUE[0] = 0.4985 * (potVal-512);
  }

  Serial.print("HUE1 = "); Serial.println(HUE[0]);
  Serial.print("HUE2 = "); Serial.println(HUE[1]);
  Serial.print("HUE3 = "); Serial.println(HUE[2]);
  analogWrite(redPIN, HUE[0]);
  analogWrite(greenPIN, HUE[1]);
  analogWrite(bluePIN, HUE[2]);
}
