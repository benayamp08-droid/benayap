#include <LiquidCrystal.h>

int tbkanan=1;
int tbkiri=2;
int tbenter=3;

int tbrk;
int tbrki;
int tbre;

int led1=4;
int led2=5;
int led3=6;
int led4=A0;

int x = 0;
int y=0;
int z=0;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
      pinMode(led3,OUTPUT);
        pinMode(led4,OUTPUT);

  pinMode(tbkanan,INPUT_PULLUP);
  pinMode(tbkiri,INPUT_PULLUP);
  pinMode(tbenter,INPUT_PULLUP);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("nilai : ");
}

void loop() {
  // put your main code here, to run repeatedly:
tbrk=digitalRead(tbkanan);
tbrki=digitalRead(tbkiri);
tbre=digitalRead(tbenter);


lcd.setCursor(9, 0);
lcd.print(x);
lcd.setCursor(10, 0);
lcd.print("     ");

if (x<0){
  x=0;
}

if (x>4){
  x=4;
}

 if(digitalRead(tbkanan)== 0){
  x = x + 1;
    delay(200);
 }

 if(digitalRead(tbkiri)== 0){
  x = x -1;
    delay(200);
 }

 if(tbre==0){
  y=1;
  z=x;
  delay(200);
 }




if(y == 1) {
if(z== 0) {
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  digitalWrite(led4,0);
}
if(z== 1) {
  digitalWrite(led1,1);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  digitalWrite(led4,0);
}
if(z == 2){
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,0);
  digitalWrite(led4,0);
}
if(z == 3){
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  digitalWrite(led4,0);
}
if(z == 4){
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  digitalWrite(led4,1);
}
}
}

