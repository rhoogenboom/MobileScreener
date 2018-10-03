#include <ESC.h>
#include "defines.h"
#include "variables.h"

ESC CrusherESC (4, 1000, 2000, 1500);


void setup() {
  delay(5000);
  // put your setup code here, to run once:
  CrusherESC.arm();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=1500;i<=1550;i++) {
    CrusherESC.speed(i);
    delay(50);
  }
  for (int i=1550;i>=1500;i--) {
    CrusherESC.speed(i);
    delay(50);
  }
}
