/*
Projekt:    kgv
Autor:      Michael Good
Datum:      05.09.2024
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

#include <stdio.h>

// Funktion, um den GGT von zwei Zahlen zu finden
int findeGGT(int a, int b) {
    // Euklidischer Algorithmus zur Berechnung des GGT
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funktion, um das KGV von zwei Zahlen zu finden
int findeKGV(int a, int b) {
    // Verhindere Division durch Null
    if (a == 0 || b == 0) {
        return 0;
    }

    // Verwende die Formel: KGV(a, b) = |a * b| / GGT(a, b)
    return ((a * b) / findeGGT(a, b));
}

int main() {
    int zahl1, zahl2;

    // Eingabe der beiden Zahlen
    printf("Geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);

    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);

    // Finde und zeige das KGV an
    printf("Das KGV von %d und %d ist %d\n", zahl1, zahl2, findeKGV(zahl1, zahl2));

    return 0;
}
