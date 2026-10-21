#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

volatile int buttonVariable;
volatile bool started = false;
volatile unsigned long time = 0;
volatile unsigned long tick = 0;
const unsigned long interval = 1000; //1 sec

void setup() {
  buttonVariable = 0;

  lcd.begin(16, 2);

  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);

  // Attach ISRs to the interrupts corresponding to pins 21 and 20 (INT0 and INT1)
  attachInterrupt(digitalPinToInterrupt(20), start, RISING);
  attachInterrupt(digitalPinToInterrupt(21), reset, CHANGE);
}

void loop() {
  if (buttonVariable == 1) {
    lcd.clear();         // Erase the LCD
    buttonVariable = 0;  // Global variable re-initialized
  }
  delay(1000);
  if(started && (millis() - tick >= interval)){
    tick += interval;
    time = time + 1 % 60;
  }
  lcd.setCursor(6, 0);
  lcd.print("Time: ");
  lcd.setCursor(7, 1);
  lcd.print(time);
}

// First ISR function
void start() {
  started = true;
}

// Second ISR function
void reset() {
  started = false;
  time = 0;
  lcd.setCursor(8, 1);
  lcd.print(" ");
}