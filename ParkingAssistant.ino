// Parking Assistant using Ultrasonic Sensor, LEDs, and Buzzer

int trigPin = 12;
int echoPin = 13;
int buttonPin = 8;
int duration;
int distance;
int buttonstate;
int blueled = 2;
int greenled = 3;
int redled = 4;
int whiteled = 5;
int buzzer = 6;   // Define buzzer pin

void setup()
{
  pinMode(trigPin, OUTPUT);    // Define trigPin as an output
  pinMode(echoPin, INPUT);     // Define echoPin as an input
  pinMode(buttonPin, INPUT);   // Define buttonPin as an input

  // Define LEDs as outputs
  for (int i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(buzzer, OUTPUT);     // Define buzzer as an output
  Serial.begin(9600);          // Initialize serial at 9600 baud
}

void loop()
{
  // Read the state of the button
  buttonstate = digitalRead(buttonPin);

  // Set the state of the white LED to match the button state
  digitalWrite(whiteled, buttonstate);

  // If the button is pressed (white LED is on), turn off other LEDs and buzzer
  if (buttonstate == HIGH) {
    digitalWrite(blueled, LOW);
    digitalWrite(greenled, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(buzzer, LOW);  // Turn off the buzzer
    Serial.println("Parking finished");
  } 
  else {
    // Send a pulse from the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echoPin, and calculate the distance in cm
    duration = pulseIn(echoPin, HIGH);
    distance = duration / 58;

    // Check the distance and set LED states accordingly
    if (distance > 10 && distance < 50) {
      digitalWrite(blueled, HIGH);
      Serial.println("SAFE ZONE");
    } else {
      digitalWrite(blueled, LOW);
    }

    if (distance == 10) {
      digitalWrite(greenled, HIGH);
      Serial.println("PERFECT");
    } else {
      digitalWrite(greenled, LOW);
    }

    if (distance < 10) {
      digitalWrite(redled, HIGH);
      digitalWrite(buzzer, HIGH);   // Turn on the buzzer
      Serial.println("WARNING");
    } else {
      digitalWrite(redled, LOW);
      digitalWrite(buzzer, LOW);    // Turn off the buzzer
    }
  }
}
