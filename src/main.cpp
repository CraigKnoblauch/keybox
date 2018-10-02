#include <Arduino.h>
#include <Matrix.cpp>

int col[4] = {12, 11, 10, 9};
int row[2] = {6, 5};

Matrix matrix = Matrix( sizeof(row), row, sizeof(col), col );

void setup() {
    matrix.begin();
}

void loop() {
    // Loop through all the LED's
    for(int i = 0; i < sizeof(row)/4; i++) {
        for(int j = 0; j < sizeof(col)/4; j++) {
            matrix.setLED(i, j);
            delay(500);
        }
    }
}
