#include <LiquidCrystal.h>

int potensi = A5;
int nilaiPot;
int nilaiSkala;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
  lcd.begin(16, 2);
  // lcd.setCursor(8,0); // Dihapus karena tidak digunakan
}

void loop() {
  nilaiPot = analogRead(potensi);
  nilaiSkala = map(nilaiPot, 0, 1023, 1, 130);


  lcd.setCursor(0, 0);
  lcd.print("nilaiPot: ");
  lcd.print(nilaiSkala);
  lcd.print("   "); 


  lcd.setCursor(0, 1);
  if (nilaiSkala >= 90) {
    lcd.print("baik banget");
  } 
  else if (nilaiSkala >= 70) {
    lcd.print("oklah      "); 
  } 
  else if (nilaiSkala >= 50) {
    lcd.print("okaja     ");
  } 
  else {
    lcd.print("bosok      "); 
  }

  
  delay(200); 
}
