#include "TrimPot.h"

TrimPot::TrimPot(int wiper, int cw) {
    this->wiper = wiper;
    this->cw = cw;

    pinMode(wiper, INPUT);
    pinMode(cw, OUTPUT);
}

int TrimPot::begin(int n) {
    int status = 0;

    digitalWrite(cw, HIGH);
    status = setNumSelections(n);

    return status;
}

int TrimPot::getSelection() {
    int val = analogRead(wiper);

    /**
    * For some amount of selections N, the amount of possible values per selection,
    * m, is equal to 1024/N (I've decided to take the floor for now until I figure out
    * how to distribute the remainders).
    * Given this arrangement, the values are distributed like so:
    *
    * 0 to m-1, m to 2m-1, ..., (N-1)m to Nm - 1
    */

    int m = 1024/num_selections;

    // if none of the selections are matched, it's likely the remainders have accumulated
    // such that the val is not in the range, thus it will not be set in the loop, but should
    // still be the last selection
    int selection = num_selections - 1;

    for(int i = 1; i <= num_selections; i++) {
        if( val >= ( (i-1)*m ) && val <= ( i*m - 1 ) ) {
            selection = i - 1;
            break;
        }
    }

    return selection;
}

int TrimPot::setNumSelections(int n) {
    int status = 0;
    if( n <= 1024 && n >= 1 ) {
        num_selections = n;
    } else {
        status = -1;
    }

    return status;
}

String TrimPot::debug() {
    String info;

    info = String( "Num Selections = " );
    info.concat(num_selections);
    info.concat("\n");

    info.concat("CW Pin: ");
    info.concat(cw);
    info.concat("\n");

    info.concat("Wiper Pin: ");
    info.concat(wiper);
    info.concat("\n");

    return info;
}
