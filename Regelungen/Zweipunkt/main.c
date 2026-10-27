//
// Created by peter on 10/27/26.
//
#include <stdio.h>
#include <stdint.h>

uint8_t zp_regeln(double sollwert, double toleranz, double messwert) {

    if (sollwert - messwert > toleranz) {
        return 1;
    }
    return 0;

}


int main() {

    const double sollwert = 21;
    const double toleranz = 0.5;
    double messwert = 0;
    double dt = 30;

    for (int i=0;  i<100; i+= dt) {

        if (zp_regeln(sollwert, toleranz, messwert)) {
            

        }

    }




}