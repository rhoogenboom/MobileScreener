#include <JC_Button.h>

const byte 
  up(32),
  down(33),
  toggle(34);     // the number of the pushbutton pi

Button btnUP(up, false, false, 25), btnDN(down, false, true, 25);
ToggleButton btnToggle(toggle);

const int
    MIN_COUNT(0),
    MAX_COUNT(59);
    
void setup() {
  // initialize the pushbutton pin as an input:
  btnUP.begin();
  btnDN.begin();
  btnToggle.begin();
  
  Serial.begin(9600);
  Serial.println(F("Setting up"));
}

void loop() {
  static int
        count,                          // the number that is adjusted
        lastCount(-1);                  // previous value of count (initialized to ensure it's different when the sketch starts)
    enum states_t {WAIT, INCR, DECR};   // states for the state machine
    static states_t STATE;              // current state machine state

  btnUP.read();
  btnDN.read();
  btnToggle.read();
  

  if (btnToggle.changed()) {
    Serial.print(F("Toggle changed to:"));
    Serial.println(btnToggle.toggleState());
  }

//    switch (STATE)
//    {
//        case WAIT:                              // wait for a button event
//            if (btnUP.wasPressed())
//                STATE = INCR;
//            else if (btnDN.wasPressed())
//                STATE = DECR;
//            break;
//
//        case INCR:
//            ++count;                            // increment the counter
//            count = min(count, MAX_COUNT);      // but not more than the specified maximum
//            STATE = WAIT;
//            break;
//
//        case DECR:
//            --count;                            // decrement the counter
//            count = max(count, MIN_COUNT);      // but not less than the specified minimum
//            STATE = WAIT;
//            break;
//    }

    if (btnUP.isPressed()) {
        ++count;                            // increment the counter
        count = min(count, MAX_COUNT);      // but not more than the specified maximum
    }
    if (btnDN.isPressed()) {
            --count;                            // increment the counter
            count = max(count, MIN_COUNT);      // but not more than the specified maximum
    }
    
    if (count != lastCount)         // print the count if it has changed
    {
        lastCount = count;
        Serial.println(count, DEC);
    }

}
