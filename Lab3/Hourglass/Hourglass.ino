#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
unsigned long time;
unsigned long tick = 0;
const unsigned long interval = 1000; //1 sec
unsigned int i = 0;

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
  lcd.begin(16, 2);
  lcd.createChar(0, hg1);
  lcd.createChar(1, hg2);
  lcd.createChar(2, hg3);
  lcd.createChar(3, hg4);
  lcd.createChar(4, hg5);
  lcd.createChar(5, hg6);
  lcd.createChar(6, hg7);
}


void loop() {
  // put your main code here, to run repeatedly:
  time = millis();

  if(time - tick >= interval){
    tick += interval;
		lcd.setCursor(7, 0);
		lcd.print(time / 1000 % 60);
		lcd.setCursor(7, 1);
		if(i == 0){
				lcd.write(byte(i));
		}
		else{
				lcd.write(i);
		}
		i = (i + 1) % 7;
	}
}
