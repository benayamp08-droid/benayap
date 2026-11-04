#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 6, 8, 9, 10, 11);

int tombolkiri  = A0;  
int tombolkanan = A1; 
int tombolMenu  = A2;  
int tombolenter = A3; 
int led         = 12; 

int jam   = 12;
int menit = 0;
int detik = 0;

int alarmJam   = 0;
int alarmMenit = 0;
int alarmDetik = 0;

int alarmAktif   = 0;   
int alarmBunyi   = 0;   
int konterLed    = 0; 

int konterMilidetik = 0;
int waktuSebelumnya = 0;

int halaman = 0;
int perluUpdateLCD = 1; 

int statusMenuSblm  = HIGH;
int statusKananSblm = HIGH;
int statusKiriSblm  = HIGH;
int statusEnterSblm = HIGH;

void setup() {
  pinMode(tombolkiri, INPUT_PULLUP);
  pinMode(tombolkanan, INPUT_PULLUP);
  pinMode(tombolMenu, INPUT_PULLUP);
  pinMode(tombolenter, INPUT_PULLUP);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  lcd.begin(16, 2);
  lcd.print("Jam Digital");
  delay(1500);
  lcd.clear();
  
  waktuSebelumnya = millis();
}

void loop() {
  int waktuSekarang = millis();

  if (waktuSekarang - waktuSebelumnya >= 100) { 
    waktuSebelumnya = waktuSekarang;
    konterMilidetik = konterMilidetik + 100;

    if (konterMilidetik >= 1000) {
      konterMilidetik = 0;


      detik++;
      if (detik >= 60) {
        detik = 0;
        menit++;
        if (menit >= 60) {
          menit = 0;
          jam++;
          if (jam >= 24) {
            jam = 0;
          }
        }
      }

      if (alarmAktif == 1) {
        if (alarmBunyi == 0) {
          int detikBerkurang = 0;
          
          if (alarmDetik > 0) {
            alarmDetik--;
            detikBerkurang = 1;
          } 
          
          if (detikBerkurang == 0) {
            if (alarmMenit > 0) {
              alarmMenit--;
              alarmDetik = 59;
              detikBerkurang = 1;
            }
          }
          
          if (detikBerkurang == 0) {
            if (alarmJam > 0) {
              alarmJam--;
              alarmMenit = 59;
              alarmDetik = 59;
            }
          }
          
         
          if (alarmJam == 0) {
            if (alarmMenit == 0) {
              if (alarmDetik == 0) {
                alarmBunyi = 1;        
                konterLed = 0;         
                digitalWrite(led, HIGH); 
              }
            }
          }
        }
      }

      
      if (alarmBunyi == 1) {
        konterLed++;
        if (konterLed >= 5) {
          digitalWrite(led, LOW); // LED Kembali Mati setelah 5 detik
          alarmBunyi = 0;         
          alarmAktif = 0;         
        }
      }

      perluUpdateLCD = 1; 
    }
  }

  int statusMenuSkrg = digitalRead(tombolMenu);
  if (statusMenuSkrg == LOW) {
    if (statusMenuSblm == HIGH) {
      delay(50); 
      if (digitalRead(tombolMenu) == LOW) {
        halaman++;
        if (halaman > 6) halaman = 0;
        lcd.clear();
        perluUpdateLCD = 1;
      }
    }
  }
  statusMenuSblm = statusMenuSkrg;

  int nilaiTampil = 0;
  int batasMaks = 59;

  if (halaman == 1) { nilaiTampil = jam; batasMaks = 23; }
  if (halaman == 2) { nilaiTampil = menit; batasMaks = 59; }
  if (halaman == 3) { nilaiTampil = detik; batasMaks = 59; }
  if (halaman == 4) { nilaiTampil = alarmJam; batasMaks = 23; }
  if (halaman == 5) { nilaiTampil = alarmMenit; batasMaks = 59; }
  if (halaman == 6) { nilaiTampil = alarmDetik; batasMaks = 59; }

  if (halaman >= 1) {
    if (halaman <= 6) {
    
      int statusKananSkrg = digitalRead(tombolkanan);
      if (statusKananSkrg == LOW) {
        if (statusKananSblm == HIGH) {
          delay(50);
          if (digitalRead(tombolkanan) == LOW) {
            nilaiTampil++;
            if (nilaiTampil > batasMaks) nilaiTampil = 0;
            
            if (halaman == 1) jam = nilaiTampil;
            if (halaman == 2) menit = nilaiTampil;
            if (halaman == 3) detik = nilaiTampil;
            if (halaman == 4) alarmJam = nilaiTampil;
            if (halaman == 5) alarmMenit = nilaiTampil;
            if (halaman == 6) alarmDetik = nilaiTampil;
            
            perluUpdateLCD = 1;
          }
        }
      }
      statusKananSblm = statusKananSkrg;

      int statusKiriSkrg = digitalRead(tombolkiri);
      if (statusKiriSkrg == LOW) {
        if (statusKiriSblm == HIGH) {
          delay(50);
          if (digitalRead(tombolkiri) == LOW) {
            nilaiTampil--;
            if (nilaiTampil < 0) nilaiTampil = batasMaks;
            
            if (halaman == 1) jam = nilaiTampil;
            if (halaman == 2) menit = nilaiTampil;
            if (halaman == 3) detik = nilaiTampil;
            if (halaman == 4) alarmJam = nilaiTampil;
            if (halaman == 5) alarmMenit = nilaiTampil;
            if (halaman == 6) alarmDetik = nilaiTampil;
            
            perluUpdateLCD = 1;
          }
        }
      }
      statusKiriSblm = statusKiriSkrg;

      int statusEnterSkrg = digitalRead(tombolenter);
      if (statusEnterSkrg == LOW) {
        if (statusEnterSblm == HIGH) {
          delay(50);
          if (digitalRead(tombolenter) == LOW) {
            if (halaman >= 4) {
              alarmAktif = 1; 
            }
            halaman = 0;
            lcd.clear();
            perluUpdateLCD = 1;
          }
        }
      }
      statusEnterSblm = statusEnterSkrg;

      if (perluUpdateLCD == 1) {
        lcd.setCursor(0, 0);
        if (halaman == 1) lcd.print("Set Jam:        ");
        if (halaman == 2) lcd.print("Set Menit:      ");
        if (halaman == 3) lcd.print("Set Detik:      ");
        if (halaman == 4) lcd.print("Tmr Jam:        ");
        if (halaman == 5) lcd.print("Tmr Menit:      ");
        if (halaman == 6) lcd.print("Tmr Detik:      ");
        
        lcd.setCursor(0, 1);
        lcd.print("Val: ");
        tampilDuaDigit(nilaiTampil);
        lcd.print("        "); 
        perluUpdateLCD = 0; 
      }
    }
  }

  if (halaman == 0) {
    if (perluUpdateLCD == 1) {
      lcd.setCursor(0, 0);
      lcd.print("Jam: ");
      tampilDuaDigit(jam);
      lcd.print(":");
      tampilDuaDigit(menit);
      lcd.print(":");
      tampilDuaDigit(detik);
      lcd.print("  ");

      lcd.setCursor(0, 1);
      if (alarmAktif == 1) {
        lcd.print("Tmr: ");
        tampilDuaDigit(alarmJam);
        lcd.print(":");
        tampilDuaDigit(alarmMenit);
        lcd.print(":");
        tampilDuaDigit(alarmDetik);
        lcd.print("  ");
      } 
      if (alarmAktif == 0) {
        lcd.print("Alarm: OFF      ");
      }
      perluUpdateLCD = 0; 
    }
  }
}

void tampilDuaDigit(int val) {
  if (val < 10) {
    lcd.print("0");
  }
  lcd.print(val);
}
