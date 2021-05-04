void SetWorkLightsOn() {
  digitalWrite(WORKINGLIGHTS, HIGH);
}

void SetWorkLightsOff() {
  digitalWrite(WORKINGLIGHTS, LOW);
}

void Blink(int pin, int wait, int state) {
  digitalWrite(pin, state);   // turn the LED on (HIGH is the voltage level)
  delay(wait);                       // wait for a second
}

void QuickBlink(int pin) {
  Blink(pin, 50, HIGH);
  Blink(pin, 50, LOW);
}

void QuickBlickSequence() {
  QuickBlink(GREEN_PIN);
  QuickBlink(GREEN_PIN);
  QuickBlink(RED_PIN);
  QuickBlink(RED_PIN);
}

void SlowGreenBlink() {
  greenLEDState = !greenLEDState;
  digitalWrite(GREEN_PIN, greenLEDState);
}

void SlowRedBlink() {
  redLEDState = !redLEDState;
  digitalWrite(RED_PIN, redLEDState);
}

void FastRedBlink() {
  redLEDState = !redLEDState;
  digitalWrite(RED_PIN, redLEDState);
}

void StartSlowGreenBlink() {
  greenBlinkTimerID = timer.setInterval(slowBlinkInterval, SlowGreenBlink);
}

void StopSlowGreenBlink() {
  timer.deleteTimer(greenBlinkTimerID);
  digitalWrite(GREEN_PIN, LOW);
}

void StartSlowRedBlink() {
  redSlowBlinkTimerID = timer.setInterval(slowBlinkInterval, SlowRedBlink);
}

void StopSlowRedBlink() {
  timer.deleteTimer(redSlowBlinkTimerID);
  digitalWrite(RED_PIN, LOW);
}

void CreateQBTimer() {
  timer.setTimer(quickBlinkInterval, QuickBlickSequence, 5);
}

void StartQuickRedBlink() {
  redFastBlinkTimerID = timer.setInterval(fastBlinkInterval, FastRedBlink);
}

void StopQuickRedBlink() {
  timer.deleteTimer(redFastBlinkTimerID);
  digitalWrite(RED_PIN, LOW);
}

void StartQuickBlinkSequence() {
  blinkSequenceTimerID = timer.setInterval(fastBlinkInterval, QuickBlickSequence);
}

void StopQuickBlinkSequence() {
  timer.deleteTimer(blinkSequenceTimerID);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

