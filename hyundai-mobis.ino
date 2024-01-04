int bledPin = 13; // blue LED will flicker when the ultrasonic waves sensor detects an object nearby 
int gledPin1 = 4;
int gledPin2 = 6;
int gledPin3 = 8;
int rledPin1 = 3;
int rledPin2 = 5;
int rledPin3 = 7;
int trigPin = 9;
int echoPin = 10;
int buzzPin = 2;
const long interval = 10000;  // interval at which to blink (milliseconds)

void setup(){
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(bledPin, OUTPUT);
  pinMode(gledPin1, OUTPUT);
  pinMode(gledPin2, OUTPUT);
  pinMode(gledPin3, OUTPUT);
  pinMode(rledPin1, OUTPUT);
  pinMode(rledPin2, OUTPUT);
  pinMode(rledPin3, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}

int rledState = LOW;
int gledState = HIGH;
unsigned long previousMillis = 0;  // will store last time LED was updated

void loop(){
  unsigned long currentMillis = millis();
  // set the LED with the ledState of the variable:
  digitalWrite(rledPin1, rledState);
  digitalWrite(rledPin2, rledState);
  digitalWrite(rledPin3, rledState);
  digitalWrite(gledPin1, gledState);
  digitalWrite(gledPin2, gledState);
  digitalWrite(gledPin3, gledState);
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    // if the LED is off turn it on and vice-versa:
    if (rledState == LOW && gledState == HIGH){
      rledState = HIGH;
      gledState = LOW;
    }
    else if (rledState == HIGH && gledState == LOW){
      rledState = LOW;
      gledState = HIGH;
    }
  }
  // ultrasonic sensor detects objects if the distance is less than 20
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration / 29.0 / 2.0;
  if (distance < 20){
    digitalWrite(bledPin, HIGH);
    if (gledState == HIGH){
      digitalWrite(buzzPin, LOW);
    }
    else {
      digitalWrite(buzzPin, HIGH);
    }
  }
  else if (distance > 20){
    digitalWrite(bledPin, LOW);
    digitalWrite(buzzPin, LOW);
  }
}  