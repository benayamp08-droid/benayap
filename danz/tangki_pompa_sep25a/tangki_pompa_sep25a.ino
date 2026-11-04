#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);    

int x;
int y;
int z;

int tb=3;
int potensi=A5;
int led1=5;
int led2=6;
int btbt;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);

pinMode(tb,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

x = analogRead(A0);
btbt= digitalRead(tb);

y = map(x, 0, 1023, 0, 255);
if (y >= 170) {
  z = 2;
}
else if (y >= 85) {
  z = 1;
}
else {
  z = 0;
}


if(y<=15){
  digitalWrite(led1,0);
  digitalWrite(led2,0);
}

if (z==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("sistem kendli");
  lcd.setCursor(0,1);
  lcd.print("tangki menu");
}

if(z==1){
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print(">pompa 1<");
  lcd.setCursor(4,1);
  lcd.print(" pompa 2 ");
}
if (z==2){
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print(" pompa 1 ");
  lcd.setCursor(4,1);
  lcd.print(">pompa 2<");
}
if (btbt==0){
  z=5;
}
if(z==4){
  digitalWrite(led1,1);
  digitalWrite(led2,0);
}
if(z==5){
  digitalWrite(led1,0);
  digitalWrite(led2,1);
}
delay(200);
}















