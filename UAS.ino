const int ledPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pin LED yang terhubung
bool running = false;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT); // Mengatur pin LED sebagai OUTPUT
  }

  Serial.begin(9600); // Mengaktifkan komunikasi serial untuk menerima input
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read(); // Membaca karakter dari Serial Monitor

    // Mematikan semua lampu
    for (int i = 0; i < 8; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    if (input == 'A') {
      int decimalNumber = 243; // Nilai desimal 'A' dalam ASCII

      // Konversi desimal ke biner
      String binaryNumber = "";
      int tempNumber = decimalNumber; // Simpan angka desimal sementara untuk diubah
      for (int i = 0; i < 8; i++) {
        if (tempNumber % 2 == 1) {
          binaryNumber = "1" + binaryNumber; // Menambahkan digit biner 1 di depan
        } else {
          binaryNumber = "0" + binaryNumber; // Menambahkan digit biner 0 di depan
        }
        tempNumber /= 2; // Bagi angka desimal dengan 2
      }

      // Mengontrol LED berdasarkan hasil konversi biner
      for (int i = 0; i < 8; i++) {
        if (binaryNumber.charAt(i) == '1') {
          digitalWrite(ledPins[i], HIGH); // Menghidupkan LED
        } else {
          digitalWrite(ledPins[i], LOW); // Mematikan LED
        }
      }
      running = false;
    } else if (input == 'B') {
      running = true;

    } else if (input == 'C') {
      digitalWrite(ledPins[0], HIGH); 
      running = false;
    } 
    else if (input == 'D') {
      digitalWrite(ledPins[1], HIGH); 
      running = false;
    }
    else if (input == 'E') {
      digitalWrite(ledPins[2], HIGH); 
      running = false;
    }
    else if (input == 'F') {
      digitalWrite(ledPins[3], HIGH);
      running = false;
    }
    else if (input == 'G') {
      digitalWrite(ledPins[4], HIGH); 
      running = false;
    } 
    else if (input == 'H') {
      digitalWrite(ledPins[5], HIGH); 
      running = false;
    }
    else if (input == 'I') {
      digitalWrite(ledPins[6], HIGH); 
      running = false;
    }
    else if (input == 'J') {
      digitalWrite(ledPins[7], HIGH);
      running = false;
    }

  }
  if (running) {
    // Menjalankan LED dari kanan ke kiri secara terus menerus
    for (int i = 0; i <= 7; i++) {
      digitalWrite(ledPins[i], HIGH); // Menghidupkan LED
      delay(200);
      digitalWrite(ledPins[i], LOW); // Mematikan LED
      delay(100);
    }
  }
}
