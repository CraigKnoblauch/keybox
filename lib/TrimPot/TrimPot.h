#ifndef _trimpot_h_
#define _trimpot_h_

#include <Arduino.h>

/**
* The purpose of this responsibility of this class includes
* Managing the outputs of certain positions of the trim pot
*/
class TrimPot {
private:
    int wiper; /** The analog pin number that the wiper of the trimpot is connected to */
    int cw;   /** The digital pin number that the cw pin of the trimpot is connected to */
    int ccw; /** The digital pin number that the ccw pin of the trimpot is connected to */
    int num_selections; /** The number of possible selections the trimpot can represent. Capped at 1024 */

public:
    TrimPot(int wiper, int cw);
    int begin(int num_selections); /** Initialize the trimpot */
    int getValue(); /** Wrapper for analogRead(wiper) */
    int setNumSelections(int n); /** Sets the num_selections variable. Returns 0 if the number is in range, -1 otherwise */
    int TrimPot::getSelection();
    String TrimPot::debug(); /** Print information about this object */

};

#endif
