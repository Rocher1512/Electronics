//Libraries 
#include <Adafruit_NeoPixel.h>
#define PIN 7 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(35, PIN, NEO_GRB + NEO_KHZ800);

//setting the 4 digit display
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int D1 = 4;
int D2 = 3;
int D3 = 2;
int D4 = 5;
int zero = 191;
int one = 6;
int two = 91;
int three = 79;
int four = 102;
int five = 109;
int six = 125;
int seven = 7;
int eight = 255;
int nine = 239;
int bits = 0;
int displaynumber = 0;

//neopixel
int speeds = 100;
int amount = 1;
int directions = 1;
int i = 0;
//timing
long timing = 0;
long times;

//buzzer
int pin13 = 13;

void setup() {
  //setting up the pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  //buzzer set up
  pinMode(pin13, OUTPUT);
  //setting the neopixel
  strip.begin();
}

void loop() {
  //displays a number on the display
  givenum(displaynumber);
  //showing the neopixel on the strip
  for(int j =0; j < 10; j++){
    strip.setPixelColor(i + (j*directions), 30, 0, 0);
  }
  strip.setPixelColor(i +(11 * directions), 0, 0, 0);
  strip.show();
  //uses the time to move the neopixel
  times = millis();
  if(times > timing){
      timing = timing + speeds;
      i = i + amount;  
    }
    //turning the neopixel around
    if(i < 1){
      i = 9;
      amount = 1;
      directions = -1;
      speeds = speeds - 20;
      displaynumber++;
    }
    //turning the neopixel around
    if(i > 35){
      i = 26;
      amount = -1;
      directions = 1;
      speeds = speeds - 20;
      displaynumber++;
    }
    //making sure the speed isn't too fast
    if(speeds < 40){
      speeds = 100;
    }
}



void givenum(int i){
    //splits the number into its 4 digits
    int numleft = 0;
    int nummidleft = 0;
    int nummidright = 0;
    int numright = 0;
    while(i >= 1000){
      numleft ++;
      i -= 1000;
    }
    while(i >= 100){
      nummidleft ++;
      i -= 100;
    }
    while(i >= 10){
      nummidright ++;
      i -= 10;
    }
    while(i >= 1){
      numright ++;
      i -= 1;
    }
  //displays the first digit
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  picking(nummidleft);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, bits);
  digitalWrite(latchPin, HIGH);
  delay(5);
  //displays the second digit
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  picking(nummidright);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, bits);
  digitalWrite(latchPin, HIGH);
  delay(5);
  //displays the third digit
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
  picking(numright);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, bits);
  digitalWrite(latchPin, HIGH);
  delay(5);
  //displays the fourth digit
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  picking(numleft);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, bits);  
  digitalWrite(latchPin, HIGH);
  delay(5);
  }
  //picks the correct bits for the display
  void picking(int i){
    if(i == 0){
      bits = zero;
    }
    else if(i == 1){
      bits = one;
    }
    else if(i == 2){
      bits = two;
    }
    else if(i == 3){
      bits = three;
    }
    else if(i == 4){
      bits = four;
    }
    else if(i == 5){
      bits = five;
    }
    else if(i == 6){
      bits = six;
    }
    else if(i == 7){
      bits = seven;
    }
    else if(i == 8){
      bits = eight;
    }
    else if(i == 9){
      bits = nine;
    }
  }
