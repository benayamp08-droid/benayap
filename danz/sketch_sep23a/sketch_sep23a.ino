#include <LiquidCrystal.h>
int potensi=A5;
int nilaiPot;
int nilaiSkala;
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  // put your setup code here, to run once:

lcd.begin(16,2);
lcd.setCursor(8,0);

}

void loop() {
  // put your main code here, to run repeatedly:
nilaiPot = analogRead(potensi);
nilaiSkala = map(nilaiPot, 0, 1023, 1, 130);
    
lcd.setCursor(0,0);
lcd.print("nilaiPot: ");
lcd.print(nilaiSkala);


if (nilaiSkala>=90){
  lcd.setCursor(0,1);
  lcd.print("baik banget");
  delay(90);
}
else if (nilaiSkala>=70){
  lcd.setCursor(0,1);
  lcd.print("oklah          ");
  delay(90);
}
else if (nilaiSkala>=50){
  lcd.setCursor(0,1);
  lcd.print("ok aja       ");
  delay(90);
}
else {
  lcd.setCursor(0,1);
  lcd.print("bosok               ");
  delay(90);
}
delay(200);
}
