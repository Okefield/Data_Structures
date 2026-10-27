#include <stdio.h>
#include <stdint.h>


uint8_t zp_regeln(double sollwert, double toleranz, double messwert, uint8_t vorheriger_zustand) {
    if (messwert < sollwert - toleranz) {
        return 1;
    }
    if (messwert > sollwert + toleranz) {
        return 0;
    }

    return vorheriger_zustand;
}

int main() {
    const double sollwert = 21.0;
    const double T_umgebung = 5.0;
    const double T_start = 15.0;
    const double verlust = 0.0005;
    const double heizleistung = 0.015;
    const double toleranz = 0.5;

    double dt = 1.5;
    double messwert = T_start;
    uint8_t heizung = 0;


    for (double t = 0; t < 3600; t += dt) {


        heizung = zp_regeln(sollwert, toleranz, messwert, heizung);


        double delta_verlust = verlust * (messwert - T_umgebung) * dt;
        double delta_gewinn = (heizung ? heizleistung : 0.0) * dt;

        messwert = messwert + delta_gewinn - delta_verlust;


        printf("%6.1f;%5.2f\n",t, messwert);
    }

    return 0;
}