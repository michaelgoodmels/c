#include <stdio.h>

// Funktion, um den GGT mithilfe des euklidischen Algorithmus zu finden
int findeGGT(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        int abs = 0;
        int findeGGT = 0;
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
    return (abs(a * b) / findeGGT(a, b));
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
