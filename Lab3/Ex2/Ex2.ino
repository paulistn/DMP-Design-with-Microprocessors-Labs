#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Character matrix for the first character: every line is a row of pixels of
// the character
byte happy[8] = {
  B00000,
  B11011,
  B11011,
  B00000,
  B00000,
  B10001,
  B01110,
};

// Matrix for the second character
byte sad[8] = {
  B00000,
  B11011,
  B11011,
  B00000,
  B00000,
  B01110,
  B10001,
};

void setup() {
  lcd.begin(16, 2);

  // The 2 characters are stored in the CGROM, user defined area, pos. 0 and 1
  lcd.createChar(0, happy);
  lcd.createChar(1, sad);

  // Display the first line: a string followed by the 1st user defined char
  lcd.setCursor(0, 0);
  lcd.print("Happy ");
  lcd.write(byte(0));  // See the difference between print and write

  /*
   When you are referring the "0" user defined char you must write a cast to
   the "byte" type, otherwise the compiler throws an error. Exception is the
   case when you are referring a varaiable:
     byte zero = 0;
     lcd.write(zero);
  */

  // Display the second line
  lcd.setCursor(0, 1);
  lcd.print("Sad ");
  lcd.write(1);  // when you are referring other characters then "0" it is not
                 // necessary to cast
}

void loop() {}