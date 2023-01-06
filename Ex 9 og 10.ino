/*
Opgave 9 og opgave 10.

Link: 
https://learn.adafruit.com/thermistor/using-a-thermistor
https://www.electronicwings.com/arduino/thermistor-interfacing-with-arduino-uno


*/

int pinThermo = A0;
int ledG = 2;
int ledY = 4;
int ledR = 6;

void setup() {
  Serial.begin(9600);
  pinMode(ledG,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledR,OUTPUT);
}

void loop() {
  int sensorVal = analogRead(pinThermo);
  float voltage = ((sensorVal* 5.0)/1023.0);
  float resistance = ((5 * ( 10 / voltage)) - 10);
  resistance = resistance * 1000; //Resistance in ohms
  float steinHart = log(resistance);
  float temperature = ( 1 / ( 0.001129148 + ( 0.000234125 * steinHart ) + ( 0.0000000876741 * steinHart * steinHart * steinHart ) ) ); /* Temperature in Kelvin */
  temperature = temperature - 273.15;
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("\xC2\xB0");

  if(temperature < 26){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
  } else if(temperature >= 26 && temperature <= 29){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);
  }else{
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);
  }
}
