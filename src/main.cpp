#include <Arduino.h>

int col[4] = {12, 11, 10, 9};
int row[2] = {6, 5};

void setup() {
    for(int i = 0; i < sizeof(col)/4; i++) {
        pinMode(col[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(row)/4; i++) {
        pinMode(row[i], OUTPUT);
    }
}

void reset() {
    for(int i = 0; i < sizeof(col)/4; i++) {
        analogWrite(col[i], 0);
    }
    for(int i = 0; i < sizeof(row)/4; i++) {
        analogWrite(row[i], 0);
    }
}


void led0On() {
    analogWrite(col[0], 168);
    analogWrite(row[0], 0);
    analogWrite(row[1], 255);
}

void led1On() {
    analogWrite(col[1], 168);
    analogWrite(row[0], 0);
    analogWrite(row[1], 255);
}

void led2On() {
    analogWrite(col[2], 168);
    analogWrite(row[0], 0);
    analogWrite(row[1], 255);
}

void led3On() {
    analogWrite(col[3], 168);
    analogWrite(row[0], 0);
    analogWrite(row[1], 255);
}

void led4On() {
    analogWrite(col[0], 168);
    analogWrite(row[1], 0);
    analogWrite(row[0], 255);
}

void led5On() {
    analogWrite(col[1], 168);
    analogWrite(row[1], 0);
    analogWrite(row[0], 255);
}

void led6On() {
    analogWrite(col[2], 168);
    analogWrite(row[1], 0);
    analogWrite(row[0], 255);
}

void led7On() {
    analogWrite(col[3], 168);
    analogWrite(row[1], 0);
    analogWrite(row[0], 255);
}

void loop() {
    reset();
    led0On();
    delay(500);
    reset();
    led1On();
    delay(500);
    reset();
    led2On();
    delay(500);
    reset();
    led3On();
    delay(500);
    reset();
    led4On();
    delay(500);
    reset();
    led5On();
    delay(500);
    reset();
    led6On();
    delay(500);
    reset();
    led7On();
    delay(500);
    reset();
}
// void reset() {
//     for(int i = 0; i < sizeof(col)/4; i++) {
//         analogWrite(col[i], 0);
//     }
//     for(int i = 0; i < sizeof(row)/4; i++) {
//         analogWrite(row[i], 168);
//     }
// }
//
// void ledOn(int coli, int rowi) {
//     analogWrite(col[coli], 168);
//     analogWrite(row[rowi], 0);
// }
//
// void setup() {
//     for(int i = 0; i < sizeof(col)/4; i++) {
//         pinMode(col[i], OUTPUT);
//     }
//     for(int i = 0; i < sizeof(row)/4; i++) {
//         pinMode(row[i], OUTPUT);
//     }
//     reset();
// }
//
// void loop() {
//     ledOn(0, 0);
//     delay(500);
//     reset();
//     ledOn(1, 0);
//     delay(500);
//     reset();
//     ledOn(2, 0);
//     delay(500);
//     reset();
//     ledOn(3, 0);
//     delay(500);
//     reset();
//     ledOn(0, 1);
//     delay(500);
//     reset();
//     ledOn(1, 1);
//     delay(500);
//     reset();
//     ledOn(2, 1);
//     delay(500);
//     reset();
//     ledOn(3, 1);
//     delay(500);
//     reset();
//     // for(int c = 0; c < sizeof(col)/4; c++) {
//     //     for(int r = 0; r < sizeof(row)/4; r++) {
//     //         ledOn(c, r);
//     //         delay(500);
//     //         reset();
//     //     }
//     // }
// }
