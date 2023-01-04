int ianden = 2;
int ifjerde = 3;
int iottende = 4;

int tal = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ianden, OUTPUT);
  pinMode(ifjerde, OUTPUT);
  pinMode(iottende, OUTPUT);

}

// https://www.instructables.com/Build-a-Simple-Binary-Counter-using-your-Arduino/

void loop() {
  
  if ((tal % 2) > 0){digitalWrite(ianden, HIGH);} else {digitalWrite(ianden, LOW);}
  if ((tal % 4) > 1){digitalWrite(ifjerde, HIGH);} else {digitalWrite(ifjerde, LOW);}
  if ((tal % 8) > 3){digitalWrite(iottende, HIGH);} else {digitalWrite(iottende, LOW);}

  tal++;
  delay(500);
  if (tal > 7) {
    tal = 0;
  }
  Serial.println(tal);
}