#include <LiquidCrystal.h>

int tombol = 2;
int led2 = 5;
int led1 = 6;
int potensi = A5;
int nilaiPot;
int nilaiSkala;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int menuSekarang = -1; 
int statusPompaAktif = 0;

void setup() {
  pinMode(tombol, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  lcd.begin(16, 2);
  

  lcd.setCursor(0, 0);
  lcd.print("sistem kendali");
  lcd.setCursor(0, 1);
  lcd.print("tangki");
  delay(2000); 
  lcd.clear();
}

void loop() {
  nilaiPot = analogRead(potensi);
  

  int menuDipilih = map(nilaiPot, 0, 1023, 0, 2);

  
  if (menuDipilih == 0) {
    statusPompaAktif = 0; 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

 
  if (menuDipilih != menuSekarang) {
    menuSekarang = menuDipilih;
    lcd.clear();
    
    if (menuSekarang == 0) {
 
      lcd.setCursor(0, 0);
      lcd.print("sistem kendali");
      lcd.setCursor(0, 1);
      lcd.print("menu pompa");
    } 
    else if (menuSekarang == 1) {
    
      lcd.setCursor(0, 0);
      lcd.print("> pompa");
      lcd.setCursor(0, 1);
      lcd.print("  pompa2");
    } 
    else if (menuSekarang == 2) {
    
      lcd.setCursor(0, 0);
      lcd.print("  pompa");
      lcd.setCursor(0, 1);
      lcd.print("> pompa2");
    }
  }

  
  if (digitalRead(tombol) == LOW) {
    delay(50); 
    if (digitalRead(tombol) == LOW) { 
      
  
      if (menuSekarang == 1) {
        statusPompaAktif = 1;
      } 
      else if (menuSekarang == 2) {
        statusPompaAktif = 2;
      }
      
   
      while(digitalRead(tombol) == LOW); 
    }
  }


  if (statusPompaAktif == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } 
  else if (statusPompaAktif == 2) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  } 
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  delay(50); 
}
