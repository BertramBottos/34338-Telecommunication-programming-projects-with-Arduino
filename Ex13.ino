int led1PIN = 2;
int led2PIN = 4;
int led3PIN = 6;
int led4PIN = 8;
int led5PIN = 10;
int buttonPIN = 3;
int stall = 30;

volatile int level;
volatile int ledLight;
volatile bool levelUpAttemt = false;

void setup() {
  Serial.begin(9600);
  pinMode(led1PIN, OUTPUT);
  pinMode(led2PIN, OUTPUT);
  pinMode(led3PIN, OUTPUT);
  pinMode(led4PIN, OUTPUT);
  pinMode(led5PIN, OUTPUT);

  level = 1;
  digitalWrite(led1PIN, LOW);
  digitalWrite(led2PIN, LOW);
  digitalWrite(led3PIN, LOW);
  digitalWrite(led4PIN, LOW);
  digitalWrite(led5PIN, LOW);
  attachInterrupt(digitalPinToInterrupt(buttonPIN), buttenPressed, RISING);
}

void loop() {
  gamelevel(level);
  Serial.print("Your current level is: ");
  Serial.println(level);
}

void gamelevel(int level) {
  if (levelUpAttemt) {
    delay(1000);
    Serial.println("Attemted Level up");
    levelUpAttemt = false; 
  }
  if (level == 11) {
    win();
    ledLight = 4;
  } 
  else if (level > 11) {
    reWind();
  } 
  else if (level > 8 && level < 11) {
    ledLight = random(1, 6);
    runled();
    delay(500 - (level * stall));
  } 
  else {
    runled();
    delay(500 - (level * stall * 1.1));
  }

}

void win() {
  digitalWrite(led1PIN, LOW);
  digitalWrite(led2PIN, LOW);
  digitalWrite(led3PIN, LOW);
  digitalWrite(led4PIN, LOW);
  digitalWrite(led5PIN, LOW);
  delay(200);
  digitalWrite(led1PIN, HIGH);
  digitalWrite(led2PIN, HIGH);
  digitalWrite(led3PIN, HIGH);
  digitalWrite(led4PIN, HIGH);
  digitalWrite(led5PIN, HIGH);
  delay(200);
}

void reWind() {
  level = 1;
}

// Runs the light of the LED
void runled() {
  if (ledLight > 5) {
    ledLight = 1;
  }
  if (ledLight == 1) {
    digitalWrite(led1PIN, HIGH);
    digitalWrite(led2PIN, LOW);
    digitalWrite(led3PIN, LOW);
    digitalWrite(led4PIN, LOW);
    digitalWrite(led5PIN, LOW);

  } else if (ledLight == 2) {
    digitalWrite(led1PIN, LOW);
    digitalWrite(led2PIN, HIGH);
    digitalWrite(led3PIN, LOW);
    digitalWrite(led4PIN, LOW);
    digitalWrite(led5PIN, LOW);
  } else if (ledLight == 3) {
    digitalWrite(led1PIN, LOW);
    digitalWrite(led2PIN, LOW);
    digitalWrite(led3PIN, HIGH);
    digitalWrite(led4PIN, LOW);
    digitalWrite(led5PIN, LOW);
  } else if (ledLight == 4) {
    digitalWrite(led1PIN, LOW);
    digitalWrite(led2PIN, LOW);
    digitalWrite(led3PIN, LOW);
    digitalWrite(led4PIN, HIGH);
    digitalWrite(led5PIN, LOW);
  } else if (ledLight == 5) {
    digitalWrite(led1PIN, LOW);
    digitalWrite(led2PIN, LOW);
    digitalWrite(led3PIN, LOW);
    digitalWrite(led4PIN, LOW);
    digitalWrite(led5PIN, HIGH);
  } else {
    digitalWrite(led1PIN, LOW);
    digitalWrite(led2PIN, LOW);
    digitalWrite(led3PIN, LOW);
    digitalWrite(led4PIN, LOW);
    digitalWrite(led5PIN, LOW);
  }
  ledLight++;
}

void buttenPressed() {
  bool state = false;
  if (ledLight == 4) {
    state = true;
  } else {
    state = false;
  }
  pointGiven(state);
  levelUpAttemt = true;
  ledLight = 1;
}

void pointGiven(bool state) {
  if (state) {
    digitalWrite(led1PIN, HIGH);
    digitalWrite(led2PIN, LOW);
    digitalWrite(led3PIN, HIGH);
    digitalWrite(led4PIN, LOW);
    digitalWrite(led5PIN, HIGH);
    level++;
  } else {
    digitalWrite(led1PIN, LOW);
    digitalWrite(led2PIN, LOW);
    digitalWrite(led3PIN, LOW);
    digitalWrite(led4PIN, LOW);
    digitalWrite(led5PIN, LOW);
  }
}