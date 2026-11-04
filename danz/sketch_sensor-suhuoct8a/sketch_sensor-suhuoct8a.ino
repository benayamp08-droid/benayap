#include <DHT11.h>
#include <LiquidCrystal.h>

int rs = 5, en = 6, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


DHT11 dht11(4); 

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Menginisialisasi");
  lcd.setCursor(0, 1);
  lcd.print("Sensor DHT...");
  

  delay(2000);
  lcd.clear();
}

void loop() {
 
  int suhu = dht11.readTemperature();
  int kelembapan = dht11.readHumidity();

 {
    lcd.setCursor(0, 0);
    lcd.print("Suhu  : ");
    lcd.print(suhu); 
    lcd.write(223);     
    lcd.print("C   ");   

    lcd.setCursor(0, 1);
    lcd.print("Lembab: ");
    lcd.print(kelembapan); 
    lcd.print("%   ");    
  }

  delay(2000);
}
