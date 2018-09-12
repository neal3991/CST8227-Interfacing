int a = 500;
int redPin= 4;
int greenPin = 3;
int bluePin = 5;
int BUTTON = 8;
int val = 0;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(BUTTON, INPUT);
}
void loop() {
    setColor(255, 0, 0); // Red Color
    setColor(0, 255, 0); // Green Color
    setColor(0, 0, 255); // Blue Color
}
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  delaypull();
}
void delaypull(){
  for(int i = 0; i < 10; i++){
    if (digitalRead (BUTTON) == LOW){
       while (digitalRead (BUTTON) == LOW){
    }
      while (digitalRead (BUTTON) == HIGH){
    }
      randomCol();  
      }
      delay(500/10);
    }
  }
void randomCol(){
  analogWrite(redPin, random(256));
  analogWrite(greenPin, random(256));
  analogWrite(bluePin, random(256));
  while (digitalRead (BUTTON) == LOW){
    }
  while (digitalRead (BUTTON) == HIGH){
    }
 
  randomCol();
}

