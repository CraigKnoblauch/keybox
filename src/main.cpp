#include <Arduino.h>
#include <Keyboard.h>
#include <TrimPot.h>

#define CW_PIN 6
#define WIPER_PIN 0

TrimPot trimpot = TrimPot(WIPER_PIN, CW_PIN); // specify how to setup the trimpot

void setup() {
    trimpot.begin(3); //specify number of selections
    Serial.begin(9600);

}

void loop() {
    int selection = trimpot.getSelection();
    switch(selection) {
        case 0:
            Serial.println("Selection 0");
            break;

        case 1:
            Serial.println("Seleciton 1");
            break;

        case 2:
            Serial.println("Selection 2");
            break;

        default:
            break;
    }
    delay(500);
}
