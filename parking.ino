const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 3;
const int buzzer= 6;
const int ledPin1=5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Send a trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);//roundtrip for wave sent & back
  long duration1= duration/2;//one way speed
  int distance = duration1 * 0.0343 ; //speed of travel for time/2 * speed = length 


  int delayTime = map(distance, 5, 100, 50, 1000);  // clamp between 50ms and 1s
  delayTime = constrain(delayTime, 50, 1000);       // avoid erratic values

  // Flash the LED
  if (distance<20){
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(delayTime / 2);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzer, LOW);
  delay(delayTime / 2);
  }
  else{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(delayTime / 2);
  digitalWrite(ledPin1, LOW);
  digitalWrite(buzzer, LOW);
  delay(delayTime / 2);
  }

  // For debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
