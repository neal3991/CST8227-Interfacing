//Pin connected to ST_CP of 74HC595
int latchPin = 16;
//Pin connected to SH_CP of 74HC595
int clockPin = 15;
////Pin connected to DS of 74HC595
int dataPin = 14;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  //count up routine
  for (int j = 0; j < 256; j++) {
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, j);
    //return the latch pin high to  chip that it
    //no longer needs to listen for informsignalation
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }
}