/* Arduino: Switch color of RGB led with a button. */

int R = 3;
int G = 4;
int B = 5;

int IN = 3;

int current = 0;

int rgb[] = { R, G, B };

void setup() {
  pinMode(IN, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);  
  pinMode(B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(IN) == HIGH) {
    current++;
    current = current == 3 ? 0 : current;
    delay(500);
  }
  digitalWrite(R, LOW);  
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);  
  digitalWrite(rgb[current], HIGH);
  delay(100);
}
