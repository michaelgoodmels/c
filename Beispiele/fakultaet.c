/*
########################################################################################################################
# Project: Fakultät                                                                                         #
# autor: Michael Good                                                                                               #
# date: 13.10.2024                                                                                                     #
# version: 0.0.1                                                                                                       #
# contact: michael.good@bzbs.ch                                                                                  #
########################################################################################################################
*/

#include <stdio.h>

int main() {
    int zahl;
    unsigned long long fakultät = 1;

    // Eingabeanforderung
    printf("Geben Sie eine positive ganze Zahl ein: ");
    scanf("%d", &zahl);

    // Überprüfen, ob die Zahl negativ ist
    if (zahl < 0) {
        printf("Die Fakultät ist für negative Zahlen nicht definiert.\n");
    } else {
        // Berechnung der Fakultät mittels einer for-Schleife
        for (int i = 1; i <= zahl; i++) {
            fakultät *= i; // fakultät = fakultät * i
        }
        printf("Die Fakultät von %d ist: %llu\n", zahl, fakultät);
    }

    return 0;
}
