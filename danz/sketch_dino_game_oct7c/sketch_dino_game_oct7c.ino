#include <LiquidCrystal.h>

// Inisialisasi pin LCD sesuai dengan rangkaian Anda
const int rs = 5, en = 6, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buton = 2; // Pin tombol

// Karakter kustom untuk Dinosaurus dan Kaktus (Rintangan)
byte dinoKarakter[8] = { 
  B00111, B00101, B00111, B10100, B11111, B01010, B01010, B00000 
};
byte kaktusKarakter[8] = { 
  B00100, B00101, B10101, B10101, B11111, B00100, B00100, B00100 
};

// Variabel Posisi Game
int posisiDinoY = 1;        // 1 = bawah (jalan kaki), 0 = atas (melompat)
int posisiKaktusX = 15;     // Rintangan mulai dari kolom paling kanan
int skor = 0;
bool gameOver = false;

// Variabel untuk mengatur delay lompatan
bool sedangMelompat = false;
unsigned long waktuMulaiLompat = 0;
const unsigned long durasiLompat = 100; // Durasi lompat cepat (100 ms)

void setup() {
  lcd.begin(16, 2);
  pinMode(buton, INPUT_PULLUP); // Menggunakan internal pull-up agar lebih stabil

  // Membuat karakter kustom di memory LCD
  lcd.createChar(0, dinoKarakter);
  lcd.createChar(1, kaktusKarakter);

  // Tampilan Awal / Start Screen
  lcd.setCursor(3, 0);
  lcd.print("Dino Game");
  lcd.setCursor(2, 1);
  lcd.print("Tekan Tombol!");

 
  while(digitalRead(buton) == HIGH) {
    delay(10);
  }
  lcd.clear();
}

void loop() {
  if (!gameOver) {

    if (digitalRead(buton) == LOW && !sedangMelompat) {
      sedangMelompat = true;
      waktuMulaiLompat = millis(); 
      posisiDinoY = 0;             
    }

    // Cek apakah durasi melompat sudah habis
    if (sedangMelompat) {
      if (millis() - waktuMulaiLompat >= durasiLompat) {
        sedangMelompat = false;
        posisiDinoY = 1;
      }
    }


    posisiKaktusX--;
    if (posisiKaktusX < 0) {
      posisiKaktusX = 15; 
      skor++;            
    }

    if (posisiKaktusX == 2 && posisiDinoY == 1) {
      gameOver = true;
    }

    lcd.clear();

    lcd.setCursor(2, posisiDinoY);
    lcd.write(byte(0));

    lcd.setCursor(posisiKaktusX, 1);
    lcd.write(byte(1));

    lcd.setCursor(12, 0);
    lcd.print(skor);

    delay(250);
  } else {
  
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("GAME OVER!");
    lcd.setCursor(0, 1);
    lcd.print("Skor:");
    lcd.print(skor);
    lcd.print(" Rst:Tkn"); 

    delay(500); 


    while(digitalRead(buton) == HIGH) {
      delay(10); 
    }
    
  
    skor = 0;
    posisiKaktusX = 15;
    sedangMelompat = false;
    posisiDinoY = 1;
    gameOver = false;
    lcd.clear();
  }
}
