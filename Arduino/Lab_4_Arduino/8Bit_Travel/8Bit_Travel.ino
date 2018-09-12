//Pin connected to ST_CP of 74HC595
int latchPin = 15;
//Pin connected to SH_CP of 74HC595
int clockPin = 16;
////Pin connected to DS of 74HC595
int dataPin = 14;
 
byte leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}
 
void loop() 
{
  leds = 0;
  //updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    updateShiftRegister();
    if(i > 0){
      bitClear(leds, (i-1));
      updateShiftRegister();
      }
    delay(300);
  }
  for (int i = 8; i > (-1); i--) {
    bitSet(leds, i);
    updateShiftRegister();
    if(i < 8){
      bitClear(leds, (i+1));
      updateShiftRegister();
      }
    delay(300);
  }
}
 
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
