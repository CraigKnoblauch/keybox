#include <Arduino.h>

#define ANALOG_IN_PIN 0 //A0
#define V_OUT_PIN 13 // When configured with digitalWrite, this pin will output 5V or 3V

#define ROW0 5
#define ROW1 4
#define COL0 7
#define COL1 6

void reset() {
    digitalWrite(COL0, LOW);
    digitalWrite(COL1, LOW);
    digitalWrite(ROW0, LOW);
    digitalWrite(ROW0, LOW);
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(V_OUT_PIN, OUTPUT);
    pinMode(ANALOG_IN_PIN, INPUT);
    digitalWrite(V_OUT_PIN, HIGH);

    // Set up the matrix
    pinMode(COL0, OUTPUT);
    pinMode(COL1, OUTPUT);
    pinMode(ROW0, OUTPUT);
    pinMode(ROW1, OUTPUT);
}

void loop() {
    // observe the reading from the trimpot, and print which led should be turned on.
    int trimpot = analogRead(ANALOG_IN_PIN);

    if( trimpot < 255 ) {

        Serial.println("LED (0, 0)");
        reset();
        digitalWrite(COL0, HIGH);
        digitalWrite(ROW0, LOW);

    } else if( trimpot < 511 ) {

        Serial.println("LED (0, 1)");
        reset();
        digitalWrite(COL1, HIGH);
        digitalWrite(ROW0, LOW);

    } else if( trimpot < 767 ) {

        Serial.println("LED (1, 0)");
        reset();
        digitalWrite(COL0, HIGH);
        digitalWrite(ROW1, LOW);

    } else {

        Serial.println("LED (1, 1)");
        reset();
        digitalWrite(COL1, HIGH);
        digitalWrite(ROW1, LOW);

    }
}
