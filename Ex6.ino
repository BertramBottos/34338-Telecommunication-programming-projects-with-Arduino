int aPIN = 7;
int bPIN = 3;
int cPIN = 4;
int dPIN = 5;
int ePIN = 6;

char SerialInput;

void setup() {
  // Setting up the pins
  Serial.begin(9600);

  pinMode(aPIN, OUTPUT);
  pinMode(bPIN, OUTPUT);
  pinMode(cPIN, OUTPUT);
  pinMode(dPIN, OUTPUT);
  pinMode(ePIN, OUTPUT);


  char mychar = '4';
  int val = mychar - '0';
  mychar = val + 'A' - 1;
  Serial.print(mychar);
}

void loop() {

  //Serial.println(SerialInput);

  if(Serial.available()) {
    SerialInput = Serial.read();
  }


  if(SerialInput == 'a') {
    digitalWrite(aPIN, HIGH);
    digitalWrite(bPIN, LOW);
    digitalWrite(cPIN, LOW);
    digitalWrite(dPIN, LOW);
    digitalWrite(ePIN, LOW);
  }
  else if (SerialInput == 'b') {
    digitalWrite(aPIN, LOW);
    digitalWrite(bPIN, HIGH);
    digitalWrite(cPIN, LOW);
    digitalWrite(dPIN, LOW);
    digitalWrite(ePIN, LOW);
  }
  else if (SerialInput == 'c') {
    digitalWrite(aPIN, LOW);
    digitalWrite(bPIN, LOW);
    digitalWrite(cPIN, HIGH);
    digitalWrite(dPIN, LOW);
    digitalWrite(ePIN, LOW);
  }
  else if (SerialInput == 'd') {
    digitalWrite(aPIN, LOW);
    digitalWrite(bPIN, LOW);
    digitalWrite(cPIN, LOW);
    digitalWrite(dPIN, HIGH);
    digitalWrite(ePIN, LOW);
  }
  else if (SerialInput == 'e') {
    digitalWrite(aPIN, LOW);
    digitalWrite(bPIN, LOW);
    digitalWrite(cPIN, LOW);
    digitalWrite(dPIN, LOW);
    digitalWrite(ePIN, HIGH);
  }
else {
    digitalWrite(aPIN, LOW);
    digitalWrite(bPIN, LOW);
    digitalWrite(cPIN, LOW);
    digitalWrite(dPIN, LOW);
    digitalWrite(ePIN, LOW);
  }
  

}
