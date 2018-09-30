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
        analogWrite( (this->row_pins)[i], FIVE_VOLTS );
    }

    // drive all columns low
    for(int i = 0; i < this->num_cols; i++) {
        analogWrite( (this->col_pins)[i], ZERO_VOLTS );
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
    analogWrite( (this->row_pins)[row], ZERO_VOLTS );
    analogWrite( (this->col_pins)[col], THREE_THREE_VOLTS );

}
