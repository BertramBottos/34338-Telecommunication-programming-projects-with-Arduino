int redPIN = A3;
int greenPIN = A1;
int bluePIN = A0;

int HUE[3] = {10,10,10};

void setup() {
  pinMode(redPIN, OUTPUT);
  pinMode(greenPIN, OUTPUT);
  pinMode(bluePIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    for (int i=0; i<3; i++) {
    HUE[i] = Serial.parseInt();
    }
  }
  Serial.print("HUE1 = "); Serial.println(HUE[0]);
  Serial.print("HUE2 = "); Serial.println(HUE[1]);
  Serial.print("HUE3 = "); Serial.println(HUE[2]);
  digitalWrite(redPIN, HUE[0]);
  digitalWrite(greenPIN, HUE[1]);
  digitalWrite(bluePIN, HUE[2]);
}
