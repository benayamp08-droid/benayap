#include <LiquidCrystal.h>

// Inisialisasi pin LCD
int rs = 5, en = 6, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Inisialisasi pin tombol dan LED
int tombolkiri   = 1;
int tombolkanan  = 2;
int tombolMenu   = 3;
int tombolenter  = 4;
int led          = 12; // Dipindah ke pin 12 agar tidak bentrok dengan tombolenter

// Variabel Waktu Tunggal (Total detik dalam int)
int totalDetikJam   = 43200; // Default jam 12:00:00 (12 * 3600)
int totalDetikAlarm = 0;     // Menyimpan sisa detik hitung mundur alarm

// Variabel Kontrol
int alarmAktif = 0; // 0 = mati, 1 = aktif
int alarmBunyi = 0; // 0 = diam, 1 = bunyi
int konterLed  = 0; // Menghitung durasi LED menyala

// Sistem Konter Pengganti Delay Besar agar Tombol Responsif
int konterDetik = 0; 

// Variabel Navigasi Menu
int halaman = 0;

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
}

void loop() {
  // Delay kecil 10 milidetik agar loop berjalan sangat cepat memantau tombol
  delay(10); 
  konterDetik++;

  // Blok ini dieksekusi setiap 100 siklus (10ms * 100 = 1000ms atau 1 detik)
  if (konterDetik >= 100) {
    konterDetik = 0; // Reset konter detik

    if (alarmBunyi == 0) {
      // Tambah 1 detik pada jam utama
      totalDetikJam++;
      if (totalDetikJam >= 86400) { 
        totalDetikJam = 0;
      }

      // Jalankan hitung mundur timer alarm jika aktif
      if (alarmAktif == 1) {
        totalDetikAlarm--;
        
        // Cek apakah timer hitung mundur sudah habis
        if (totalDetikAlarm <= 0) {
          totalDetikAlarm = 0;
          alarmBunyi = 1;
          konterLed = 0;
          digitalWrite(led, HIGH); // LED Menyala
        }
      }
    }

    // Hitung durasi LED menyala (berjalan tiap detik, sampai 5 detik)
    if (alarmBunyi == 1) {
      konterLed++;
      if (konterLed >= 5) {
        digitalWrite(led, LOW);
        alarmBunyi = 0;
        alarmAktif = 0; // Timer otomatis mati setelah selesai
      }
    }

    // Refresh tampilan LCD khusus Halaman 0 agar angka jam detik berkedip tiap detik
    if (halaman == 0) {
      int j = totalDetikJam / 3600;
      int m = (totalDetikJam % 3600) / 60;
      int d = totalDetikJam % 60;

      lcd.setCursor(0, 0);
      lcd.print("Jam: ");
      tampilDuaDigit(j);
      lcd.print(":");
      tampilDuaDigit(m);
      lcd.print(":");
      tampilDuaDigit(d);

      lcd.setCursor(0, 1);
      if (alarmAktif == 1) {
        int aj = totalDetikAlarm / 3600;
        int am = (totalDetikAlarm % 3600) / 60;
        int ad = totalDetikAlarm % 60;
        lcd.print("Tmr: ");
        tampilDuaDigit(aj); 
        lcd.print(":");
        tampilDuaDigit(am);
        lcd.print(":");
        tampilDuaDigit(ad);
      }
      if (alarmAktif == 0) {
        lcd.print("Alarm: OFF      ");
      }
    }
  }

  // ==========================================
  // PEMBACAAN TOMBOL SANGAT RESPONSIF
  // ==========================================
  
  // Pembacaan Tombol Menu
  if (digitalRead(tombolMenu) == LOW) {
    halaman++;
    if (halaman > 6) {
      halaman = 0;
    }
    delay(250); // Debounce pencegah tombol tertekan ganda
    lcd.clear();
  }

  // Logika Pengaturan Menu (Halaman 1 sampai 6)
  if (halaman >= 1) {
    if (halaman <= 6) {
      int j = totalDetikJam / 3600;
      int m = (totalDetikJam % 3600) / 60;
      int d = totalDetikJam % 60;
      
      int aj = totalDetikAlarm / 3600;
      int am = (totalDetikAlarm % 3600) / 60;
      int ad = totalDetikAlarm % 60;

      String labelMenu = "";
      int nilaiTampil = 0;
      int batasMaks = 59;

      // Halaman 1-3: Set Jam Utama
      if (halaman == 1) { labelMenu = "Set Jam:";   nilaiTampil = j; batasMaks = 23; }
      if (halaman == 2) { labelMenu = "Set Menit:"; nilaiTampil = m; batasMaks = 59; }
      if (halaman == 3) { labelMenu = "Set Detik:"; nilaiTampil = d; batasMaks = 59; }

      // Halaman 4-6: Set Timer Alarm
      if (halaman == 4) { labelMenu = "Tmr Jam:";   nilaiTampil = aj; batasMaks = 23; }
      if (halaman == 5) { labelMenu = "Tmr Menit:"; nilaiTampil = am; batasMaks = 59; }
      if (halaman == 6) { labelMenu = "Tmr Detik:"; nilaiTampil = ad; batasMaks = 59; }

      // Tombol Kanan untuk menambah nilai
      if (digitalRead(tombolkanan) == LOW) {
        nilaiTampil++;
        if (nilaiTampil > batasMaks) {
          nilaiTampil = 0;
        }
        // Update langsung ke detik jam
        if (halaman == 1) totalDetikJam = (nilaiTampil * 3600) + (m * 60) + d;
        if (halaman == 2) totalDetikJam = (j * 3600) + (nilaiTampil * 60) + d;
        if (halaman == 3) totalDetikJam = (j * 3600) + (m * 60) + nilaiTampil;
        // Update langsung ke detik alarm
        if (halaman == 4) totalDetikAlarm = (nilaiTampil * 3600) + (am * 60) + ad;
        if (halaman == 5) totalDetikAlarm = (aj * 3600) + (nilaiTampil * 60) + ad;
        if (halaman == 6) totalDetikAlarm = (aj * 3600) + (am * 60) + nilaiTampil;
        
        delay(200); // Debounce
      }
      
      // Tombol Kiri untuk mengurangi nilai
      if (digitalRead(tombolkiri) == LOW) {
        nilaiTampil--;
        if (nilaiTampil < 0) {
          nilaiTampil = batasMaks;
        }
        // Update langsung ke detik jam
        if (halaman == 1) totalDetikJam = (nilaiTampil * 3600) + (m * 60) + d;
        if (halaman == 2) totalDetikJam = (j * 3600) + (nilaiTampil * 60) + d;
        if (halaman == 3) totalDetikJam = (j * 3600) + (m * 60) + nilaiTampil;
        // Update langsung ke detik alarm
        if (halaman == 4) totalDetikAlarm = (nilaiTampil * 3600) + (am * 60) + ad;
        if (halaman == 5) totalDetikAlarm = (aj * 3600) + (nilaiTampil * 60) + ad;
        if (halaman == 6) totalDetikAlarm = (aj * 3600) + (am * 60) + nilaiTampil;
        
        delay(200); // Debounce
      }

      // Tombol Enter untuk menyimpan dan kembali ke menu utama
      if (digitalRead(tombolenter) == LOW) {
        if (halaman >= 4) {
          alarmAktif = 1; 
        }
        halaman = 0;
        delay(300); // Debounce
        lcd.clear();
      }

      // Menampilkan informasi menu secara realtime saat disetel
      lcd.setCursor(0, 0);
      lcd.print(labelMenu);
      lcd.setCursor(0, 1);
      lcd.print("variable: ");
      tampilDuaDigit(nilaiTampil);
      lcd.print("         ");
    }
  }
}

// Fungsi bantu format 2 digit
void tampilDuaDigit(int val) {
  if (val < 10) {
    lcd.print("0");
  }
  lcd.print(val);
}
