#include <LiquidCrystal.h>

// Inisialisasi LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Deklarasi Variabel
int y; 
int z = 0;             // Status menu aktif
int x = -1; // Untuk mendeteksi perubahan agar LCD tidak berkedip
int tb = 3; 
int pb; 
int potensi = A5; 
int led1 = 5; 
int led2 = 6; 

void setup() {
  lcd.begin(16, 2); 
  Serial.begin(9600); 
  
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(tb, INPUT_PULLUP); 
}

void loop() {
  // Membaca nilai dari komponen
  y = analogRead(potensi); 
  pb = digitalRead(tb); 

  Serial.print("Nilai Potensio: ");
  Serial.println(y); 
  delay(50); // Delay singkat untuk kestabilan pembacaan

  // --- 1. LOGIKA UTAMA: POTENSIO DI BAWAH 20 = SEMUA LED MATI ---
  if (y < 20) {
    digitalWrite(led1, LOW);  // Paksa LED 1 mati
    digitalWrite(led2, LOW);  // Paksa LED 2 mati

  }

  // --- 2. LOGIKA NAVIGASI MENU (POTENSIOMETER) ---
  // Navigasi menu hanya aktif jika LED tidak sedang menyala dan potensio >= 20
  if (z != 4 && z != 5 && z != 99) {
    if (y >= 170) {
      z = 2; // Sorot Tangki 2
    } 
    else if (y >= 85) {
      z = 1; // Sorot Tangki 1
    } 
    else {
      z = 0; // Menu Utama
    }
  }

  // --- 3. LOGIKA EKSEKUSI TOMBOL ---
  // Tombol hanya berfungsi jika sistem tidak sedang berada di posisi di bawah 20
  if (pb == 0 && z != 99) { 
    delay(50); // Debounce tombol agar pembacaan stabil
    
    // Jika tombol ditekan saat menyorot Tangki 1, AKTIFKAN LED 1
    if (z == 1) { 
      z = 4;                     // Kunci status menu ke Tangki 1 Terpilih
      digitalWrite(led1, HIGH);  // LED 1 Menyala
      digitalWrite(led2, LOW);   
    } 
    // Jika tombol ditekan saat menyorot Tangki 2, AKTIFKAN LED 2
    else if (z == 2) {
      z = 5;                     // Kunci status menu ke Tangki 2 Terpilih
      digitalWrite(led1, LOW);   
      digitalWrite(led2, HIGH);  // LED 2 Menyala
    }
  }

  // --- 4. LOGIKA PENGAMAN: PUTAR KIRI SAAT LED MENYALA ---
  // Mengembalikan menu ke awal jika potensio diputar ke kiri melewati batas ambang menunya
  if (z == 4 && y < 85) {
    digitalWrite(led1, LOW);  
    z = 0;                    
  }
  if (z == 5 && y < 170) {
    digitalWrite(led2, LOW);  
    z = 0;                    
  }

  // --- 5. LOGIKA TAMPILAN LCD ---
  if (z != x) {
    lcd.clear(); 
  }
    // Tampilan khusus ketika posisi potensio di bawah 20

    else if (z == 0) {
      lcd.setCursor(0, 0); 
      lcd.print("Kendali Tangki"); 
      lcd.setCursor(0, 1); 
      lcd.print("Menu Pompa");
    } 
    else if (z == 1) {
      lcd.setCursor(0, 0); 
      lcd.print("> Tangki 1"); 
      lcd.setCursor(0, 1); 
      lcd.print("  Tangki 2"); 
    } 
    else if (z == 2) {
      lcd.setCursor(0, 0); 
      lcd.print("  Tangki 1"); 
      lcd.setCursor(0, 1); 
      lcd.print("> Tangki 2"); 
    }
    else if (z == 4) {
      lcd.setCursor(0, 0);
      lcd.print("TANGKI 1 TERPILIH");
      lcd.setCursor(0, 1);
      lcd.print("POMPA 1 / LED1 ON");
    }
    else if (z == 5) {
      lcd.setCursor(0, 0);
      lcd.print("TANGKI 2 TERPILIH");
      lcd.setCursor(0, 1);
      lcd.print("POMPA 2 / LED2 ON");
    }
    
    x = z; // Perbarui status menu saat ini
  }

