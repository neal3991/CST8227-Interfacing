//Pin connected to ST_CP of 74HC595
int latchPin = 15;
//Pin connected to SH_CP of 74HC595
int clockPin = 16;
////Pin connected to DS of 74HC595
int dataPin = 14;
 
byte leds = 0;
byte dataEight;
byte dataSixteen;
byte dataArrayEight[10];
byte dataArraySixteen[10];
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  digitalWrite(dataPin, 0);
  digitalWrite(clockPin, 0);
  digitalWrite(latchPin, 0);
  //Arduino doesn't seem to have a way to write binary straight into the code 
  //so these values are in HEX.  Decimal would have been fine, too. 
  dataArrayEight[0] = 0xFF; //11111111
  dataArrayEight[1] = 0xFE; //11111110
  dataArrayEight[2] = 0xFC; //11111100
  dataArrayEight[3] = 0xF8; //11111000
  dataArrayEight[4] = 0xF0; //11110000
  dataArrayEight[5] = 0xE0; //11100000
  dataArrayEight[6] = 0xC0; //11000000
  dataArrayEight[7] = 0x80; //10000000
  dataArrayEight[8] = 0x00; //00000000
  dataArrayEight[9] = 0xE0; //11100000

  //Arduino doesn't seem to have a way to write binary straight into the code 
  //so these values are in HEX.  Decimal would have been fine, too. 
  dataArraySixteen[0] = 0x07; //00000111
  dataArraySixteen[1] = 0x00; //00000000
  dataArraySixteen[2] = 0x01; //00000001
  dataArraySixteen[3] = 0x03; //00000011
  dataArraySixteen[4] = 0x07; //00000111
  dataArraySixteen[5] = 0x0F; //00001111 
  dataArraySixteen[6] = 0x1F; //00011111
  dataArraySixteen[7] = 0x3F; //00111111
  dataArraySixteen[8] = 0x7F; //01111111
  dataArraySixteen[9] = 0xFF; //11111111
}
 
void loop() 
{
  for (int i = 0; i < 10; i++) {
    dataEight = dataArrayEight[i];
    bitSet(dataEight, i);
    updateShiftRegister_Eight(dataEight);
    
    dataSixteen = dataArraySixteen[i];    
    bitSet(dataSixteen, i);
    updateShiftRegister_Sixteen(dataSixteen);
    /*if(i > 0){
      bitClear(leds, (i-1));
      updateShiftRegister();
      }*/
    delay(300);
  }
  int j = 16;
  for (int i = 8; i > (-1); i--) {
    //bitSet(leds, i);
    //16

    dataSixteen = dataArraySixteen[i];   
    
    if(i < 8){
      bitClear(dataSixteen, (i+1));
      updateShiftRegister_Sixteen(dataSixteen);
    }
    /*
    if(j < 8){
      dataEight = dataArrayEight[j];
      bitClear(dataEight, (i+1));
      updateShiftRegister_Eight(dataEight);      
      }*/
    
    j--;
  delay(300);
 }
}
 
void updateShiftRegister_Eight(int x)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, x);
   digitalWrite(latchPin, HIGH);
}
void updateShiftRegister_Sixteen(int y)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, y);
   digitalWrite(latchPin, HIGH);
}
