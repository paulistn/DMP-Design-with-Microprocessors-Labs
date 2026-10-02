// Read status of buttons and send it to the PC over the
//serial connection
// Variables for reading the status of the buttons connected
//to the digital pins 4, 5
int b1;
int b2;
// variable for the transmitted status (as a decimal number)
int stat = 0;
void setup() {
// configure digital pins as inputs
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
// activate serial communication for displaying the result
// on the PC
Serial.begin(9600);
}
void loop() {
// read BTNs status
b1 = digitalRead(4);
b2 = digitalRead(5);
// combine the bits in a decimal number (stat)
stat = 100 + b2 * 10 + b1;
//transmit status
Serial.println(stat);
// delay 0.5 sec
delay(500);
}
