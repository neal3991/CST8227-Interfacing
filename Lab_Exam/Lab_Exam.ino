/* Constants */
const int sensorPin = 14; //Sensor Pin    
const int ledPin = 13;    //Teensy Led Pin    
const int redPin =  3;    //Red Pin from RGB Led
const int greenPin =  4;  //Green Pin from RGB Led
const int bluePin =  5;   //Blue Pin from RGB Led

int sensorValue = 0;         
int sensorMin = 1023;        
int sensorMax = 0;       


void setup() {
  /*Turning on Teensy LED to signal start of calibration*/
  pinMode(13, OUTPUT);
  pinMode (14, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  digitalWrite(13, HIGH);
  /*Begin Calibration within first five seconds*/
  while (millis() < 5000) {
    /* Keep reading sensor for five seconds */
    sensorValue = analogRead(sensorPin);
    /* Finding the Max for this Calibration */
    if (sensorValue > sensorMax){
      sensorMax = sensorValue;
    }
    /* Finding the Max for this Calibration */
    if (sensorValue < sensorMin){
      sensorMin = sensorValue;
    }
  }
  /* End of Calibration Signal */
  digitalWrite(13, LOW);
  Serial.print ("SensorMax ");
  Serial.println (sensorMax);
  Serial.print ("SensorMin ");
  Serial.println (sensorMin);
}

void loop() {
  /* Starting DEMO */
  sensorValue = analogRead(sensorPin);
 // sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  /* If sensor value is outside the range of Calibration constration(value, min, max)*/
  sensorValue = constrain(sensorValue, 0, 1023);
  /* Applying the specified logic for Final Demo */
  sensorValue = analogRead (sensorPin);
  if((sensorValue < (67)) && (sensorValue > (6))){
    analogWrite(bluePin, 0);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 250);
    }
  if((sensorValue >= (67))){
    analogWrite(bluePin, 0);
    analogWrite(greenPin, 0);
    analogWrite(redPin, 250);
    }
  if((sensorValue <= (6))){
    analogWrite(greenPin, 0);
    analogWrite(redPin, 0);
    analogWrite(bluePin, 250);
    }
  Serial.print ("ADC ");
  Serial.println (sensorValue);
  Serial.print ("10% of Maximum ");
  Serial.println ((0.1)*(sensorMax));
  Serial.print ("10% of Minimum ");
  Serial.println ((0.1)*(sensorMin));
  
  delay (1000);
  attachInterrupt(digitalPinToInterrupt(14), ISR,CHANGE);  
}

void ISR(){
  delay (1000);
  sensorValue = analogRead(sensorPin);
  }


