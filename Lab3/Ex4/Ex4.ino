#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

volatile int buttonVariable;

void setup() {
  buttonVariable = 0;

  lcd.begin(16, 2);
  lcd.print("A inceput");
  lcd.setCursor(0, 1);
  lcd.print("din nou");
  delay(1000);

  // (OLD WAY) The two interrupt pins 21 and 20 declared as inputs with pull-up
  // resistors activated by writing a HIGH value to the inputs
  // pinMode(20, INPUT);
  // pinMode(21, INPUT);
  // digitalWrite(20, HIGH);
  // digitalWrite(21, HIGH);

  // (NEW WAY) The two interrupt pins 21 and 20 declared as inputs with pull-up
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);

  // Attach ISRs to the interrupts corresponding to pins 21 and 20 (INT0 and INT1)
  attachInterrupt(digitalPinToInterrupt(20), functieUnu, RISING);
  attachInterrupt(digitalPinToInterrupt(21), functieDoi, CHANGE);
}

void loop() {
  if (buttonVariable == 1) {
    lcd.clear();         // Erase the LCD
    buttonVariable = 0;  // Global variable re-initialized
  }
  delay(1000);
  lcd.setCursor(0, 0);    // Set the LCD cursor
  lcd.print("Programul");  // Display a message
  lcd.setCursor(0, 1);    // Set the LCD cursor
  lcd.print("Principal");  // Display a message
}

// First ISR function
void functieUnu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Functia Unu");
}

// Second ISR function
void functieDoi() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Functia Doi");
}