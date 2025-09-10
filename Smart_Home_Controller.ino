#include <Servo.h>
#include <IRremote.h>

// --- Pin Definitions ---
int pirPin = 2;
int servoPin = 6;
int relayPin = 5;
int motorPin = 9;
int irPin = 10; // IR receiver connected here

// --- Components ---
Servo servo;

void setup() {
  Serial.begin(9600);

  // PIR setup
  pinMode(pirPin, INPUT);
  servo.attach(servoPin);

  // Relay & motor setup
  pinMode(relayPin, OUTPUT);
  pinMode(motorPin, OUTPUT);

  // IR receiver setup
  IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);
  Serial.println("Setup complete");
}

void loop() {
  // --- PIR SENSOR & SERVO CONTROL ---
  int pirState = digitalRead(pirPin);
  if (pirState == 1) {
    servo.write(90); // Move servo when motion is detected
  } else {
    servo.write(0);  // Reset position
  }
  Serial.print("PIR State: ");
  Serial.println(pirState);

  // --- IR REMOTE CONTROL ---
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    Serial.print("Received IR command: ");
    Serial.println(command);

    // Resume listening for the next IR signal
    IrReceiver.resume();

    // Execute based on command
    if (command == 1) {
      Serial.println("Turning relay ON");
      digitalWrite(relayPin, HIGH);
    } else if (command == 2) {
      Serial.println("Turning relay OFF");
      digitalWrite(relayPin, LOW);
    } else if (command == 3) {
      Serial.println("Turning motor ON");
      digitalWrite(motorPin, HIGH);
    } else if (command == 4) {
      Serial.println("Turning motor OFF");
      digitalWrite(motorPin, LOW);
    } else {
      Serial.println("Unknown command");
    }

    delay(1000); // Wait for a second after command execution
  }

  delay(500); // Slight delay for stability
}
