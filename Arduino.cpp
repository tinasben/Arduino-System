const int motionSensorPin = 2;
const int photoresistorPin = A0;
const int lightPin = 9;
int motionCounter = 0;

void setup() {
  pinMode(motionSensorPin, INPUT);
  pinMode(photoresistorPin, INPUT);
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int photoresistorValue = analogRead(photoresistorPin);
  if (photoresistorValue < 500) {  // Detect night time
    int motionValue = digitalRead(motionSensorPin);
    if (motionValue == HIGH) {
      motionCounter++;
      digitalWrite(lightPin, HIGH);
      Serial.print("Motion detected! Count: ");
      Serial.println(motionCounter);
      delay(500);  // Wait for half a second before turning off the light
      digitalWrite(lightPin, LOW);
    }
  } else {
    digitalWrite(lightPin, LOW);  // Turn off the light during the day
  }
}
