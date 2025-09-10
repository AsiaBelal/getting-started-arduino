// DC Motor Control using H-Bridge (L293D)
// Controls two DC motors in different directions with PWM

void setup() {
  // Define motor control pins as outputs
  pinMode(3, OUTPUT);  // Motor A enable (PWM)
  pinMode(5, OUTPUT);  // Motor A input
  pinMode(9, OUTPUT);  // Motor B input
  pinMode(11, OUTPUT); // Motor B enable (PWM)
}

void loop() {
  // Move motors in one direction
  analogWrite(3, 225);   // Motor A speed
  analogWrite(5, 0);     
  analogWrite(9, 0);     
  analogWrite(11, 255);  // Motor B speed
  delay(1000);           // Run for 1 second

  // Stop motors
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(9, 0);
  analogWrite(11, 0);
  delay(1000);

  // Move motors in another direction
  analogWrite(3, 0);     
  analogWrite(5, 255);   // Reverse Motor A
  analogWrite(9, 255);   // Reverse Motor B
  analogWrite(11, 0);    
  delay(1000);
}
