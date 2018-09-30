#include <Arduino.h>
#include "Matrix.h"

/**
 * Loop through all row and column pins, set them to output pins.
 * Return a Matrix object
 */
Matrix::Matrix(int num_rows, int* row_pins, int num_cols, int* col_pins) {
    // Set private variables
    this->num_rows = num_rows;
    this->row_pins = row_pins;
    this->num_cols = num_cols;
    this->col_pins = col_pins;

    // Set row pins as output pins
    for(int i = 0; i < num_rows; i++) {
        pinMode( row_pins[i], OUTPUT );
    }

    // Set column pins as output pins
    for(int i = 0; i < num_cols; i++) {
        pinMode( col_pins[i], OUTPUT );
    }
}

int Matrix::begin() {
    int status = 0;

    // drive all rows high
    for(int i = 0; i < this->num_rows; i++) {
        digitalWrite( (this->row_pins)[i], HIGH );
    }

    // drive all columns low
    for(int i = 0; i < this->num_cols; i++) {
        digitalWrite( (this->col_pins[i]), LOW );
    }

    return status;
}

int Matrix::reset() {
    return Matrix::begin();
}

int Matrix::setLED(int row, int col) {
    int status = 0;

    // Reset the matrix, then drive row low, and column high
    status = Matrix::reset();
    digitalWrite( (this->row_pins[row]), LOW );
    digitalWrite( (this->col_pins[col]), HIGH );

}
