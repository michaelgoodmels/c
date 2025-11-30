/*
Projekt:    Wochentemperatur Array
Autor:      Michael Good
Datum:      29.11.2025
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

#include <stdio.h>

int main() {
    float temperatur[7] = {2.1, 3.4, 5.0, 1.8, -0.5, 0.0, 4.2};

    float summe = 0;

    for (int i = 0; i < 7; i++) {
        summe += temperatur[i];
    }

    float durchschnitt = summe / 7;

    printf("\nDurchschnitt: %.2f %cC\n", durchschnitt, 248);


    return 0;
}
