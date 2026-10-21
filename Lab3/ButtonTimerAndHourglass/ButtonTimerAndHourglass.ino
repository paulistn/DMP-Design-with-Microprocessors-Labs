#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

volatile int buttonVariable;
volatile bool started = false;
volatile unsigned long time = 0;
volatile unsigned long tick = 0;
volatile unsigned int i = 0;
const unsigned long interval = 1000; //1 sec

byte hg1[8] = {
	0b11111,
	0b11111,
	0b11111,
	0b01110,
	0b01010,
	0b10001,
	0b10001,
	0b11111
};

byte hg2[8] = {
	0b11111,
	0b10001,
	0b11111,
	0b01110,
	0b01110,
	0b10001,
	0b10001,
	0b11111
};

byte hg3[8] = {
	0b11111,
	0b10001,
	0b10001,
	0b01110,
	0b01110,
	0b10101,
	0b10001,
	0b11111
};

byte hg4[8] = {
	0b11111,
	0b10001,
	0b10001,
	0b01110,
	0b01110,
	0b10101,
	0b11111,
	0b11111
};

byte hg5[8] = {
	0b11111,
	0b10001,
	0b10001,
	0b01010,
	0b01110,
	0b10101,
	0b11111,
	0b11111
};

byte hg6[8] = {
	0b11111,
	0b10001,
	0b10001,
	0b01010,
	0b01010,
	0b11111,
	0b11111,
	0b11111
};

byte hg7[8] = {
	0b00000,
	0b00000,
	0b11011,
	0b11101,
	0b11101,
	0b11011,
	0b00000,
	0b00000
};

void setup() {
  buttonVariable = 0;

  lcd.begin(16, 2);

  lcd.createChar(0, hg1);
  lcd.createChar(1, hg2);
  lcd.createChar(2, hg3);
  lcd.createChar(3, hg4);
  lcd.createChar(4, hg5);
  lcd.createChar(5, hg6);
  lcd.createChar(6, hg7);

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
  lcd.setCursor(6, 0);
  lcd.print("Time: ");
  lcd.setCursor(7, 1);
	lcd.print(time);
  lcd.setCursor(6, 1);
	if(i == 0){
		lcd.write(byte(i));
  }
	else{
		lcd.write(i);
	}
  if(started && (millis() - tick >= interval)){
    tick += interval;
    time = time + 1 % 60;
		i = (i + 1) % 7;
  }
}

// First ISR function
void start() {
  started = true;
}

// Second ISR function
void reset() {
  started = false;
  time = 0;
  i = 0;
  lcd.setCursor(8, 1);
  lcd.print(" ");
}