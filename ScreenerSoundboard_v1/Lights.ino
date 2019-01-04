void setWorkLightsOn() {
  digitalWrite(WORKINGLIGHTS, HIGH);
}

void setWorkLightsOff() {
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

void createQBTimer() {
  timer.setTimer(quickBlinkInterval, QuickBlickSequence, 5);
}

void StartQuickBlinkTimer() {
  quickBlinkTimerID = timer.setInterval(quickBlinkInterval, QuickBlickSequence);
}

void StopQuickBlinkTimer() {
  timer.deleteTimer(quickBlinkTimerID);
}

