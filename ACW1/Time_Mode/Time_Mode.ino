
unsigned long times;
long timing = 0;

int pinA = 3;
int pinB = 7;
int pinC = 10;
int pinD = 12;
int pinE = 13;
int pinF = 4;
int pinG = 9;
int pinDP = 11;

int D1 = 2;
int D2 = 5;
int D3 = 6;
int D4 = 8;

int amounttoadd = 1;

int delaytime = 5; 

int buttonState = 0;
int buttonPressed = 0;

int buttonState2 = 0;
int buttonPressed2 = 0;

int i = 0;
int j = 0;
int k = 0;
int l = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(pinDP, OUTPUT);
  
}
void loop() {
        buttonPressed = analogRead(A1);
        buttonPressed2 = analogRead(A2);
        //Serial.println(buttonPressed);
        //Serial.println(buttonPressed2);        
        times = millis();
        times = times;
        digitalWrite(D1, LOW);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        digitalWrite(pinDP, LOW);
        picking(i);
        delay(delaytime);
        digitalWrite(D1, HIGH);
        digitalWrite(D2, LOW);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        digitalWrite(pinDP, LOW);
        picking(j);
        delay(delaytime);
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, LOW);
        digitalWrite(D4, HIGH);
        digitalWrite(pinDP, HIGH);
        picking(k);
        delay(delaytime);
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, LOW);
        digitalWrite(pinDP, LOW);
        picking(l);
        delay(delaytime);

      if(times > timing){
        timing = times + 100;
        l += amounttoadd;
      }
        if(l > 9){
          l = 0;
          k +=  1;  
        }
        if(k > 9){
          k = 0;
          j +=  1;  
        }
        if(j > 9){
          j = 0;
          i +=  1;  
        }
        if(i > 9){
          i = 0;  
        }

        if(buttonPressed == 0){
          buttonState = 1;
        }
        if(buttonState == 1){
          if(buttonPressed > 10){
            i = 0;
            j = 0;
            k = 0;
            l = 0;
            buttonState = 0;
          }
        }

        if(buttonPressed2 == 0){
          buttonState2 = 1;
        }
        if(buttonState2 == 1){  
          if(buttonPressed2 > 100){
            if(amounttoadd == 1){
            amounttoadd = 0;
            Serial.println("set too 0");
            Serial.println(amounttoadd); 
            }
            else if(amounttoadd == 0){
            amounttoadd = 1;
            Serial.println(amounttoadd); 
            Serial.println("set too 1"); 
            }
            buttonState2 = 0;
          }
        }
     }
void picking(int i) {
  if(i == 0){
      clearthem();
      zero();
    }
  if(i == 1){
      clearthem();
      one();
    }
  if(i == 2){
      clearthem();
      two();
    }
  if(i == 3){
      clearthem();
      three();
    }
  if(i == 4){
      clearthem();
      four();
    }
  if(i == 5){
      clearthem();
      five();
    }
  if(i == 6){
      clearthem();
      six();
    }
  if(i == 7){
      clearthem();
      seven();
    }
   if(i == 8){
      clearthem();
      eight();
    }
   if(i == 9){
      clearthem();
      nine();
    }  
  }
void clearthem() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinG, LOW);
}

void zero() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinC, HIGH);
  }
void one() {
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  }
void two() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinD, HIGH);
  }
void three() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  }
void four() {
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  }
void five() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  }
void six() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  }

void seven() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  }
void eight() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinG, HIGH);
  }
void nine() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinG, HIGH);
  }
