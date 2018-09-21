#include <Arduino.h>

#define ANALOG_IN_PIN 0 //A0
#define V_OUT_PIN 13 // When configured with digitalWrite, this pin will output 5V or 3V

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(V_OUT_PIN, OUTPUT);
    pinMode(ANALOG_IN_PIN, INPUT);
    digitalWrite(V_OUT_PIN, HIGH);
}

void loop() {
    // observe the reading from the trimpot, and print which led should be turned on.
    int trimpot = analogRead(ANALOG_IN_PIN);

    if( trimpot < 255 ) {
        Serial.println("LED (0, 0)");
    } else if( trimpot < 511 ) {
        Serial.println("LED (0, 1)");
    } else if( trimpot < 767 ) {
        Serial.println("LED (1, 0)");
    } else {
        Serial.println("LED (1, 1)");
    }
}
