///////////////////////////////////////////////////////////
// AVR-DB Blink-Switch Demo 
//
// Intended to run on the Electrodragon.com  AVR128DB64 development board
// https://www.electrodragon.com/product/avr128db64-mini-develpment-board-avr128/
// 
// using Spence Konde's DxCcre for the Arduino IDE.
// https://github.com/SpenceKonde/DxCore
//
// LED active high on PC6
//
// Push button switch active low on PC7
//
// Operation:  LED blinks at 1000 ms on, 1000 ms off.  Prints diagnostic
// message to console with every LED state change.  Pressing and holding
// the push button cauess the LED to freeze (remain in current state)
// while button is in down position.
//
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// setup 
//
// this is the setup, do once, code
///////////////////////////////////////////////////////////
void setup(void) {
  // initialize serial port and send a message to the console
  Serial4.begin(57600, SERIAL_8N1);  // start the serial port
  delay(500); // let things settle
  Serial4.printf("\nAVR128DB64 Blink Switch Demo\n"); // show msg on console
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_PC6, OUTPUT);  // init PC6 at output for LED
  pinMode(PIN_PC7, INPUT); // init PC7 as input
  digitalWrite(PIN_PC7, HIGH);   // enable the pullup on PC7 input pin
}

///////////////////////////////////////////////////////////
// loop
//
// This is the Super Loop.  In the Arduino world this is really a function (not a loop)
// that is called repeatedly by the Arduino executive.  As such, any local variables
// will be lost each time when the function concludes.  If you want to retain local
// variables then wrap your loop code in a while(1) statement.
///////////////////////////////////////////////////////////
void loop(void) {
  while (1) {
    digitalWrite(PIN_PC6, LOW);   // activate LED (LED is active low)
    Serial4.printf("LED is ON\n");  // diagnostic message to consoler
    delay(1000); // keep LED in this state at least this many milliseconds
    while (!digitalRead(PIN_PC7)); // if switch is closed wait here until it goes open
    
    digitalWrite(PIN_PC6, HIGH);    // disable LED (LED is active low)
    Serial4.printf("LED is OFF\n");  // diagnostic message to consoler
    delay(1000); // keep LED in this state at least this many milliseconds
    while (!digitalRead(PIN_PC7)); // if switch is closed wait here until it goes open 
  }  
}

