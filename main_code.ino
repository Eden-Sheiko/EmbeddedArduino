const int trigPin = 9;
const int echoPin = 10;
const int IR_SENSOR_PIN = 8;
const int LIGHT_SENSOR_PIN = A2;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(IR_SENSOR_PIN, INPUT_PULLUP);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Ultrasonic Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  int irSensorState = digitalRead(IR_SENSOR_PIN);

  if (irSensorState == LOW) {
    Serial.println("IR Sensor: Obstacle detected!");
  } else {
    Serial.println("IR Sensor: No obstacle");
  }

  int lightValue = analogRead(LIGHT_SENSOR_PIN);
  Serial.print("Light Sensor Value: ");
  Serial.println(lightValue);

  delay(1000);
}
