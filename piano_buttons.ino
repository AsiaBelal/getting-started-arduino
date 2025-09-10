// Define button input pins
int push1 = 2;
int push2 = 3;
int push3 = 4;
int push4 = 5;
int push5 = 6;
int push6 = 7;
int push7 = 8;
int push8 = 9;

// Define buzzer output pin
int buzzer = 10;

void setup() {
  // Set buttons as input
  pinMode(push1, INPUT);
  pinMode(push2, INPUT);
  pinMode(push3, INPUT);
  pinMode(push4, INPUT);
  pinMode(push5, INPUT);
  pinMode(push6, INPUT);
  pinMode(push7, INPUT);
  pinMode(push8, INPUT);

  // Set buzzer as output
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Read all push buttons
  int v1 = digitalRead(push1);
  int v2 = digitalRead(push2);
  int v3 = digitalRead(push3);
  int v4 = digitalRead(push4);
  int v5 = digitalRead(push5);
  int v6 = digitalRead(push6);
  int v7 = digitalRead(push7);
  int v8 = digitalRead(push8);

  // Play tones based on button press
  if(v1 == 1) {
    tone(buzzer, 261);  // C4
  }
  if(v2 == 1) {
    tone(buzzer, 293);  // D4
  }
  if(v3 == 1) {
    tone(buzzer, 329);  // E4
  }
  if(v4 == 1) {
    tone(buzzer, 349);  // F4
  }
  if(v5 == 1) {
    tone(buzzer, 392);  // G4
  }
  if(v6 == 1) {
    tone(buzzer, 440);  // A4
  }
  if(v7 == 1) {
    tone(buzzer, 495);  // B4
  }
  if(v8 == 1) {
    tone(buzzer, 528);  // C5
  }

  delay(1000); // Wait for 1 second before checking again
}
