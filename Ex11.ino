#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int thermoPIN = A0;
float temp;
float sensorVal;
float sensorHoldVal;
float voltage;
float resistance;
float steinHart;

void setup() {
  
  lcd.begin(16, 2);
  lcd.print("Hot or Cold?");
  delay(1000);
}

void loop() {
  sensorHoldVal = 0;
  for (int i = 0; i<10;i++) {
    sensorHoldVal+=analogRead(thermoPIN);
  }
  sensorVal = sensorHoldVal / 10;
  voltage = ((sensorVal*5.0)/1023.0);
  resistance = ((5*(10/voltage))-10);
  steinHart = log(resistance*1000);
  temp = ( 1 / ( 0.001129148 + ( 0.000234125 * steinHart ) + ( 0.0000000876741 * steinHart * steinHart * steinHart ) ) )-273.15;


  
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print(char(223));
  lcd.print("C");

  lcd.setCursor(9,1);
  if (temp < 26) {
    lcd.print("SO Cold");
  }
  else if(temp >= 26 && temp < 29) {
    lcd.print("MM Nice");
  }
  else if (temp >= 29 && temp <=32) {
    lcd.print("SO HOT!");

  }
  else {
    lcd.print("LAVA??");
  }

}