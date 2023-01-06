/*
Opgave 11 
Lavet af Anders Granskov HAnsen

Forbundet plus power til sensor, hvor der så sidder en 10k resistor. Analog read er mellem sensor og resistor, minus er på den anden side af resistoren. 
*/
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int redLED = 8;
int greenLED = 9;
int bl = 10;
int tempSensor = A0;
float tempNorminal = 25 + 273.15;
int B = 3435;       //Beta værdi for sensor.
int sensorR = 10000;  //Sensor resistance.
int seriesR = 10000;  //Resistor that is in series with sensor
float tempGennem;

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(bl, OUTPUT);
  lcd.begin(16, 2);
  //lcd.print("Hello, world!");
  
}

void loop() {
  int sensorVal = analogRead(tempSensor);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (5.0 / 1023.0) * sensorVal;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float Vr = 5.0 - voltage;
  float RT = voltage / (Vr / sensorR); // resistance 
  float ln = log(RT / seriesR);
  float tempK = (1 / ((ln / B) + (1 / tempNorminal)));

  
  float temperature = tempK - 273.15;
  Serial.print(", degress C: ");
  Serial.println(temperature);

  if(temperature <= 22){
      digitalWrite(bl, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
  } else if(temperature > 22 && temperature < 26){
      digitalWrite(bl, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);    
  } else{
      digitalWrite(bl, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);    
  }

  for(int i = 0; i < 10; i++){
    tempGennem += temperature;
  }

  lcd.print(tempGennem/10);
  Serial.println(tempGennem/10);
/*
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
*/
}
