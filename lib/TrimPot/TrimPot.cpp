#include <Arduino.h>
#include "TrimPot.h"

TrimPot::TrimPot(int wiper, int cw) {
    pinMode(wiper, INPUT);
    pinMode(cw, OUTPUT);
}

int TrimPot::begin(int num_selections) {
    int status = 0;

    digitalWrite(cw, HIGH);
    status = setNumSelections(num_selections);

    return status;
}

int TrimPot::getSelection() {
    int val = analogRead(wiper);

    /**
    * Assures that the correct position is idenitifed. For example, if there are
    * 3 selection options, and the value of trimpot is 28, this would be the 0 selection.
    * It follows that (28 + 1) / 3 = 0
    */
    int selection = (val + 1) / num_selections;

    return selection;
}

int TrimPot::setNumSelections(int n) {
    int status = 0;
    if( n <= 1024 && n >= 0 ) {
        num_selections = n;
    } else {
        status = -1;
    }

    return status;
}
