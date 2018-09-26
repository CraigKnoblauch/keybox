#include <Arduino.h>

int col[4] = {12, 10, 8, 6};
int row[4] = {11, 9, 7, 5};

void reset() {
    for(int i = 0; i < sizeof(col)/4; i++) {
        digitalWrite(col[i], LOW);
    }
    for(int i = 0; i < sizeof(row)/4; i++) {
        digitalWrite(row[i], HIGH);
    }
}

void ledOn(int coli, int rowi) {
    digitalWrite(col[coli], HIGH);
    digitalWrite(row[rowi], LOW);
}

void setup() {
    for(int i = 0; i < sizeof(col)/4; i++) {
        pinMode(col[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(row)/4; i++) {
        pinMode(row[i], OUTPUT);
    }
    reset();
}

void loop() {
    for(int c = 0; c < sizeof(col)/4; c++) {
        for(int r = 0; r < sizeof(row)/4; r++) {
            ledOn(c, r);
            delay(500);
            reset();
        }
    }
}
