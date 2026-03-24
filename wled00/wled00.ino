#include <Arduino.h>
#include "wled.h"

WLED wled;

void setup() {
  wled.setup();
}

void loop() {
  wled.loop();
}
