#include <Arduino.h>
#include <Matrix.cpp>

int col[4] = {12, 11, 10, 9};
int row[2] = {8, 7};

Matrix matrix = Matrix( 2, row, 4, col );

void setup() {
    matrix.begin();
}

void loop() {
    // Loop through all the LED's, in a circle
    matrix.loopTest(1000);

}
