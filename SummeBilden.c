#include <stdio.h>

int main(void) {
    int zahl;
    int summe = 0;
    int ziffer;

    /* Zahl einlesen */
    printf("Bitte eine ganze Zahl eingeben: ");
    scanf("%d", &zahl);

    /* Falls negativ, positiv machen */
    if (zahl < 0) {
        zahl = -zahl;
    }

    /* Solange die Zahl noch Stellen hat */
    while (zahl != 0) {
        /* Letzte Ziffer bestimmen */
        ziffer = zahl % 10;

        /* Prüfen, ob ungerade */
        if (ziffer % 2 != 0) {
            summe = summe + ziffer;
        }

        /* Letzte Ziffer entfernen */
        zahl = zahl / 10;
    }

    /* Ergebnis ausgeben */
    printf("Summe der ungeraden Ziffern: %d\n", summe);

    return 0;
}
