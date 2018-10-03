#include <Arduino.h>
#include <Matrix.cpp>
#include <TrimPot.cpp>

int col[4] = {12, 11, 10, 9};
int row[2] = {8, 7};

Matrix matrix = Matrix( 2, row, 4, col );

#define CW 6
#define WIPER 0

TrimPot trimpot = TrimPot(WIPER, CW);

void setup() {
    
    matrix.begin();
    trimpot.begin(8);
    Serial.begin(9600);

}

void loop() {

    switch( trimpot.getSelection() ) {
        case 0:
            matrix.setLED(0, 0);
            break;

        case 1:
            matrix.setLED(0, 1);
            break;

        case 2:
            matrix.setLED(0, 2);
            break;

        case 3:
            matrix.setLED(0, 3);
            break;

        case 4:
            matrix.setLED(1, 0);
            break;

        case 5:
            matrix.setLED(1, 1);
            break;

        case 6:
            matrix.setLED(1, 2);
            break;

        case 7:
            matrix.setLED(1, 3);
            break;

        default:
            break;

    }

}
