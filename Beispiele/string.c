/*
Projekt:    string
Autor:      Michael Good
Datum:      11.11.2024
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

#include <stdio.h>
#include <string.h>

int main() {
    // Erstelle ein String-Array für das Wort "Schweiz"
    char land[] = "Schweiz";

    // Berechne die Länge des Arrays (inklusive Nullterminator)
    int arrayLaenge = sizeof(land) / sizeof(land[0]);

    // Ausgabe der Länge des Arrays
    printf("Die Länge des Arrays (inkl. \\0): %d\n\n", arrayLaenge);

    // Ausgabe der einzelnen Zeichen im Array
    for (int i = 0; i < arrayLaenge; i++) {
        if (land[i] == '\0') {
            printf("Position %d: '\\0' (Nullterminator)\n", i);
        } else {
            printf("Position %d: '%c'\n", i, land[i]);
        }
    }

    return 0;
}
