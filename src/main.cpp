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
    // put your main code here, to run repeatedly:
    int read = analogRead(ANALOG_IN_PIN);
    if(read % 10 == 0) {
        Serial.println(read, BIN);
    }
}
