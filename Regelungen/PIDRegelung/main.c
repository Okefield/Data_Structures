//
// Created by peter on 10/28/26.
//

#include <stdio.h>

typedef struct {
    double Kp, Ki, Kd;
    double integral;
    double letzter_fehler;
} PIDRegler;


void pid_init(PIDRegler *pid, double Kp, double Ki, double Kd) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->integral = 0.0;
    pid->letzter_fehler = 0.0;
}



int main() {
    const double sollwert = 21.0;
    const double T_umgebung = 5.0;
    const double verlust = 0.0005;
    const double heizleistung = 0.015;
    const double dt = 1.5;

    double messwert = 15.0;
    double stellwert = 0.0;

    PIDRegler regler;
    pid_init(&regler, 0.2, 0.0005, 5.0);
}