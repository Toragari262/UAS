const int ledPins[8] = {9, 8, 7, 6, 5, 4, 3, 2};
const int angkaled = sizeof(ledPins) / sizeof(ledPins[0]);
bool running;
void setup() {
  
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  Serial.begin(9600);
}

void loop() {
  int angka = Serial.parseInt();
  if (Serial.available()) {
    
    if (angka >= 0 && angka <= 255) {
          for (int i = 0; i < angkaled; i++) {
          int nilai = (angka >> i) & 1;
          digitalWrite(ledPins[i], nilai);
          running = false; 
      } 
    } 
     
    else if (angka == 256) {
      lampoff();
      running = true;  
    } 

    else if (angka == 257) {
      digitalWrite(ledPins[0], LOW);
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], LOW);
      digitalWrite(ledPins[6], LOW);
      digitalWrite(ledPins[7], HIGH);
      running = false; 
    } 

    else if (angka == 258) {
      digitalWrite(ledPins[0], LOW); 
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], LOW);
      digitalWrite(ledPins[6], HIGH);
      digitalWrite(ledPins[7], LOW);
      running = false;  
    }

    else if (angka == 259) {
      digitalWrite(ledPins[0], LOW); 
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], HIGH);
      digitalWrite(ledPins[6], LOW);
      digitalWrite(ledPins[7], LOW);
      running = false;     
    }

    else if (angka == 260) {
      digitalWrite(ledPins[0], LOW); 
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], HIGH);
      digitalWrite(ledPins[5], LOW);
      digitalWrite(ledPins[6], LOW);
      digitalWrite(ledPins[7], LOW);
      running = false;    
    }

    else if (angka == 261) {
      digitalWrite(ledPins[0], LOW); 
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], HIGH);
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], LOW);
      digitalWrite(ledPins[6], LOW);
      digitalWrite(ledPins[7], LOW);
      running = false;     
    } 

    else if (angka == 262) {
      digitalWrite(ledPins[0], LOW); 
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], LOW);
      digitalWrite(ledPins[6], LOW);
      digitalWrite(ledPins[7], LOW);
      running = false;
    }

    else if (angka == 263) {
      digitalWrite(ledPins[0], LOW); 
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], LOW);
      digitalWrite(ledPins[6], LOW);
      digitalWrite(ledPins[7], LOW);
      running = false;
    }

    else if (angka == 264) {
      digitalWrite(ledPins[0], HIGH); 
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], LOW);
      digitalWrite(ledPins[6], LOW);
      digitalWrite(ledPins[7], LOW);
      running = false;     
    }

    else if(angka >= 265){
      lampoff();
      Serial.println("angka lebih dari 264");
      running = false; 
    }
  }

  if(running){
    for (int i = angkaled; i >= 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(300);
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void lampoff(){
  digitalWrite(ledPins[0], LOW); 
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[5], LOW);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[7], LOW);
}