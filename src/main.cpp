#include <Arduino.h>
#include <Keyboard.h>

#define PINOUT 2
#define PININ  3

void setup() {
    Keyboard.begin();
    Serial.begin(9600);
    pinMode(PINOUT, OUTPUT);
    pinMode(PININ, INPUT);
    digitalWrite(PINOUT, HIGH);
}

void loop() {
    if( digitalRead(PININ) ) {
        Keyboard.print("Pressed");
    } else {
        Serial.println("NOT Pressed");
    }
    delay(1000);
}
