// Ultrasonic Sensor with Button Control
// When button is pressed, measure and print distance to Serial Monitor

int trigPin = 12;
int echoPin = 13;
int buttonPin = 8;
int duration;
int distance;
int buttonstate;

void setup() {
  pinMode(trigPin, OUTPUT);    // Define trigPin as output
  pinMode(echoPin, INPUT);     // Define echoPin as input
  pinMode(buttonPin, INPUT);   // Define buttonPin as input

  Serial.begin(9600);          // Initialize Serial Monitor
}

void loop() {
  // Read button state
  buttonstate = digitalRead(buttonPin);

  if (buttonstate == HIGH) {   // Button is pressed
    // Send ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure echo duration
    duration = pulseIn(echoPin, HIGH);

    // Convert duration to distance (in cm)
    distance = duration / 58;

    // Print distance to Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000); // Wait 1 second
  } 
  else {
    Serial.println("Button is not pressed.");
    delay(500); // Small delay to avoid flooding Serial
  }
}
