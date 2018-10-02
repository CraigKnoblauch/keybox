#ifndef _matrix_h_
#define _matrix_h_

#define FIVE_VOLTS 255
#define THREE_THREE_VOLTS 168
#define ZERO_VOLTS 0

/**
 * The purpose of the class is to simplify working with an LED matrix.
 * This will help not only for debugging the matrix, but also when we're
 * developing the final project
 */
class Matrix {
    private:
        int* row_pins; /** Array of pins used for the rows, in order */
        int  num_rows; /** Number of rows */
        int* col_pins; /** Array of pins used for the columns, in order */
        int  num_cols; /** Number of columns */
        int  reset(); /** Clear the matrix. Drive all rows high, and all columns low */

    public:
        Matrix(int num_rows, int* row_pins, int num_cols, int* col_pins);
        int begin(); /** Initialize the matrix. Drive all rows high, and all columns low */
        int setLED(int row, int col); /** Turn on the specified LED */
        void loopTest(int delay_ms); /** Loop through all the LED's and test if the matrix is working. Delay between each led 'delay_ms' miliseconds */
};

#endif
