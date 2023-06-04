const int ledPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
bool running = false;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();
    
    for (int i = 0; i < 8; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    if (input == 'A') {
      int decimalNumber = 243;
      
      String binaryNumber = "";
      int tempNumber = decimalNumber;
      for (int i = 0; i < 8; i++) {
        if (tempNumber % 2 == 1) {
          binaryNumber = "1" + binaryNumber; 
        } else {
          binaryNumber = "0" + binaryNumber;
        }
        tempNumber /= 2;
      }

      for (int i = 0; i < 8; i++) {
        if (binaryNumber.charAt(i) == '1') {
          digitalWrite(ledPins[i], HIGH); 
        } else {
          digitalWrite(ledPins[i], LOW); 
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
