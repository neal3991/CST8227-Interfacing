byte SER = 14; //data
byte LATCH = 15; //RCLK
byte CLOCK = 16; //SRCLK
void setup(){
pinMode(SER, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(LATCH, OUTPUT);
digitalWrite(SER, 0);
digitalWrite(CLOCK, 0);
digitalWrite(LATCH, 0);
delay(300);
}
void loop(){
//first bit
shiftOut(SER, CLOCK, MSBFIRST, 1); //shiftOut(dataPin, clockPin, bitOrder, value)
digitalWrite(LATCH, 1);
delay(300);
//set the latch low
digitalWrite(LATCH, 0);
//first bit
shiftOut(SER, CLOCK, MSBFIRST, 0);
digitalWrite(LATCH, 1);
delay(300);
//
// //set the latch low
digitalWrite(LATCH, 0);
}
