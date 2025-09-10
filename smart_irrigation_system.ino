#include <LiquidCrystal.h>

// Define pin numbers
int RED_LED_PIN = 13;
int GREEN_LED_PIN = 8;
int MOTOR_PIN = 9;
int MOISTURE_SENSOR_PIN = A3;
int TEMP_SENSOR_PIN = A1;

// Initialize the LCD with the pins connected to the display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set pin modes
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT);
  pinMode(MOISTURE_SENSOR_PIN, INPUT);

  // Initialize the LCD
  lcd.begin(16, 2);
}

void loop() {
  // Read sensor values
  int temperature = analogRead(TEMP_SENSOR_PIN);
  int moisture = analogRead(MOISTURE_SENSOR_PIN);

  // Display the temperature and moisture
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);

  lcd.setCursor(0, 1);
  lcd.print("Moist: ");
  lcd.print(moisture);

  // Control LEDs and motor based on sensor values
  if (moisture < 300 && temperature < 300) {
    // If moisture is low, turn on red LED and motor
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(MOTOR_PIN, HIGH);
  } else {
    // If moisture is sufficient, turn on green LED and turn off motor
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(MOTOR_PIN, LOW);
  }

  delay(1000); // Optional: delay to make the LCD more readable
}
