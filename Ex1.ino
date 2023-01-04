
int shortTime = 300;
int longTime = 750;
int endTime = shortTime + longTime;

void setup() {
  pinMode(2, OUTPUT);

}

void loop() {
  morseSOS();
  morseName();

  delay(5000);
  

}

void morseSOS() {
  blinkLed('S');
  blinkLed('O');
  blinkLed('S');
}

void morseName() {
  blinkLed('B');
  blinkLed('E');
  blinkLed('R');
  blinkLed('T');
  blinkLed('R');
  blinkLed('A');
  blinkLed('M');  

  blinkLed('A');
  blinkLed('N');
  blinkLed('D');
  blinkLed('E');
  blinkLed('R');
  blinkLed('S');

}

void blinkLed(char bokstav) {

  switch (bokstav) {
    case 'A':
      blink(shortTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'B':
      blink(longTime);
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;

    case 'C':
      blink(longTime);
      blink(shortTime);
      blink(longTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'D':
      blink(longTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'E':
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'F':
      blink(shortTime);
      blink(shortTime);
      blink(longTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'G':
      blink(longTime);
      blink(longTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'H':
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'I':
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'J':
      blink(shortTime);
      blink(longTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'K':
      blink(longTime);
      blink(shortTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'L':
      blink(shortTime);
      blink(longTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'M':
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'N':
      blink(longTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'O':
      blink(longTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'P':
      blink(shortTime);
      blink(longTime);
      blink(longTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'Q':
      blink(longTime);
      blink(longTime);
      blink(shortTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'R':
      blink(shortTime);
      blink(longTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'S':
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case 'T':
      blink(longTime);
      delay(endTime);
      break;
    
    case 'U':
      blink(shortTime);
      blink(shortTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'V':
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'W':
      blink(shortTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;

    case 'X':
      blink(longTime);
      blink(shortTime);
      blink(shortTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'Y':
      blink(longTime);
      blink(shortTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case 'Z':
      blink(longTime);
      blink(longTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case '1':
      blink(shortTime);
      blink(longTime);
      blink(longTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case '2':
      blink(shortTime);
      blink(shortTime);
      blink(longTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case '3':
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case '4':
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    
    case '5':
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case '6':
      blink(longTime);
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case '7':
      blink(longTime);
      blink(longTime);
      blink(shortTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case '8':
      blink(longTime);
      blink(longTime);
      blink(longTime);
      blink(shortTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case '9':
      blink(longTime);
      blink(longTime);
      blink(longTime);
      blink(longTime);
      blink(shortTime);
      delay(endTime);
      break;
    
    case '0':
      blink(longTime);
      blink(longTime);
      blink(longTime);
      blink(longTime);
      blink(longTime);
      delay(endTime);
      break;
    

  }

}

void blink(int length) {
  digitalWrite(2, HIGH);
  delay(length);
  digitalWrite(2, LOW);
  delay(shortTime);
}