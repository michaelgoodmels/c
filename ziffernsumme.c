/*
Projekt:    Ziffernsumme
Autor:      Michael Good
Datum:      21.09.2025
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

//Präprozessor initialisieren
#include <stdio.h>

//Hauptprogramm
int main() {
    int zahl;
    int summe = 0;
    int ziffer;

    // Zahl einlesen
    printf("Bitte geben Sie eine ganze Zahl ein: ");
    scanf("%d", &zahl);

    // Negative Zahl in positive umwandeln (damit Ziffernverarbeitung korrekt ist)
    if (zahl < 0) {
        zahl = -zahl;
    }

    // Solange Zahl ≠ 0
    while (zahl != 0) {
        // Letzte Ziffer bestimmen
        ziffer = zahl % 10;

        // Prüfen, ob Ziffer ungerade ist
        if (ziffer % 2 != 0) {
            // Ziffer zur Summe addieren
            summe += ziffer;
        }

        // Letzte Ziffer entfernen
        zahl = zahl / 10;
    }

    // Ergebnis ausgeben
    printf("Die Summe der ungeraden Ziffern ist: %d\n", summe);

    return 0;
}
