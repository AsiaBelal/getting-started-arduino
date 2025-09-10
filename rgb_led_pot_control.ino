// C++ code

const int bluePin = 3;     // Blue LED pin
const int redPin = 5;      // Red LED pin
const int greenPin = 6;    // Green LED pin
const int potPin = A2;     // Potentiometer analog pin

void setup() {
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin); // Read potentiometer value

  // Potentiometer value is in the range 0-1023
  // LED pins are in the range 0-255
  // Scale potValue to fit into 0-255 range
  int potValue2 = potValue / 4;

  analogWrite(redPin, potValue2);    // Set red component
  analogWrite(greenPin, potValue2);  // Set green component
  analogWrite(bluePin, potValue2);   // Set blue component

  Serial.println(potValue);          // Print potentiometer value
  delay(200);                        // Delay for 200 milliseconds
}
