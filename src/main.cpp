#include <Arduino.h>
#include <Matrix.cpp>

int col[4] = {12, 11, 10, 9};
int row[2] = {8, 7};

Matrix matrix = Matrix( 2, row, 4, col );

#define CW 6
#define WIPER 0

void setup() {
    matrix.begin();

    // Verify the trimpot is working
    Serial.begin(9600);
    pinMode(CW, OUTPUT);
    pinMode(WIPER, INPUT);
    digitalWrite(CW, HIGH);
}

void loop() {
    // Loop through all the LED's
    // matrix.loopTest(1000);

    int trim_val = analogRead(WIPER);
    Serial.println(trim_val*0.004882);
    delay(50);

}
