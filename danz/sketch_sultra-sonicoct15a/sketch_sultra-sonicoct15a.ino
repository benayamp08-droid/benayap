#include <LiquidCrystal.h>


int rs = 5, en = 6, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int triger = 2;
int echo = 1;

long durasi;
int jarak;

void setup() {
  lcd.begin(16, 2);
  
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);
  
  lcd.setCursor(0, 0);
  lcd.print(" Pengukur Jarak ");
  delay(2000);
  lcd.clear();
}

void loop() {
  digitalWrite(triger, LOW);
  delayMicroseconds(2);
  

  digitalWrite(triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(triger, LOW);
  
  
  durasi = pulseIn(echo, HIGH);
  

  jarak = durasi * 0.034 / 2;
  
  
  lcd.setCursor(0, 0);
  lcd.print("Jarak:");
  
  lcd.setCursor(0, 1);
  lcd.print("      ");
  lcd.setCursor(0, 1);
  lcd.print(jarak);
  lcd.print(" cm");
  
  delay(250); 
}
