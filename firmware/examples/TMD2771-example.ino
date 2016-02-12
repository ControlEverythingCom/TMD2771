// This #include statement was automatically added by the Particle IDE.
#include "TMD2771.h"

TMD2771 sensor;

void setup() {
    sensor.init();
}

void loop() {
    Serial.printf("Distance: %i \n", sensor.getDistance());
    delay(1000);
}