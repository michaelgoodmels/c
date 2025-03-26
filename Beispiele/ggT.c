/*
Projekt:    ggt
Autor:      Michael Good
Datum:      05.09.2024
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

#include <stdio.h>

// Funktion, um den GGT mithilfe des euklidischen Algorithmus zu finden
int findeGGT(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int zahl1, zahl2;

    // Eingabe der beiden Zahlen
    printf("Geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);

    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);

    // Finde und zeige den GGT an
    printf("Der GGT von %d und %d ist %d\n", zahl1, zahl2, findeGGT(zahl1, zahl2));

    return 0;
}