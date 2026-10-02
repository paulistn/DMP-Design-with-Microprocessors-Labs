// LEDs change direction when the button is pressed
const byte LED_NR = 4;
const byte MAX_VAL = (1 << (LED_NR - 1)) - 1;

int b1;
bool pressed = false;
bool directionRight = false;

unsigned int ledValue = 1;

void setup() {
// configure digital pins as inputs
pinMode(7, INPUT_PULLUP);
// activate PORTA, as output,
DDRA = 0b11111111;
}

void loop() {
// read BTNs status
b1 = digitalRead(7);

if (b1 == LOW){
  pressed = true;
}

PORTA = ledValue; 

if(directionRight){
  if(ledValue <= 1){
    ledValue = MAX_VAL + 1;
  }
  else{
    ledValue >>= 1;
  }
}
else{
  if(ledValue > MAX_VAL){
    ledValue = 1;
  }
  else{
    ledValue <<= 1;
  }
}

delay(500);

if(pressed){
  directionRight = !directionRight;
  pressed = false;
}
}