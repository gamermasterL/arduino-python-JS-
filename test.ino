#include <LiquidCrystal_I2C>
int trig = 9;
int echo = 8;
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup(){
    lcd.begin(16, 2);
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

}

void loop(){
 long duration, distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn (echo, HIGH);
  distance = duration * 17 / 1000; 

  Serial.print(distance);
  Serial.println(" Cm");

  lcd.setCursor(1, 1);    
  lcd.print(distance);
  delay(1000);     
 
}