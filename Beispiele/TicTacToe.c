/*
Projekt:    TicTacToe
Autor:      Michael Good
Datum:      29.11.2025
Version:    0.1
Kontakt:    michael.good@outlook.com
*/
#include <stdio.h>

#define SIZE 3

void spielfeld_anzeigen(char feld[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", feld[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int pruefe_sieg(char f[SIZE][SIZE], char spieler) {
    // Reihen prüfen
    for (int i = 0; i < SIZE; i++)
        if (f[i][0] == spieler && f[i][1] == spieler && f[i][2] == spieler)
            return 1;

    // Spalten prüfen
    for (int j = 0; j < SIZE; j++)
        if (f[0][j] == spieler && f[1][j] == spieler && f[2][j] == spieler)
            return 1;

    // Diagonalen prüfen
    if (f[0][0] == spieler && f[1][1] == spieler && f[2][2] == spieler)
        return 1;

    if (f[0][2] == spieler && f[1][1] == spieler && f[2][0] == spieler)
        return 1;

    return 0;
}

int feld_voll(char f[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (f[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    char feld[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char spieler = 'X';
    int zeile, spalte;

    printf("=== TIC TAC TOE ===\n\n");
    spielfeld_anzeigen(feld);

    while (1) {
        printf("Spieler %c, gib Zeile (1-3) und Spalte (1-3) ein: ", spieler);
        scanf("%d %d", &zeile, &spalte);

        // Umwandeln in 0-basierten Index
        zeile--;
        spalte--;

        // Eingabe prüfen
        if (zeile < 0 || zeile >= SIZE || spalte < 0 || spalte >= SIZE) {
            printf("Ungueltige Eingabe! Bitte 1 bis 3.\n");
            continue;
        }

        if (feld[zeile][spalte] != ' ') {
            printf("Feld ist schon belegt! Waehle ein anderes.\n");
            continue;
        }

        // Setze das Symbol
        feld[zeile][spalte] = spieler;

        // Aktualisiertes Spielfeld ausgeben
        spielfeld_anzeigen(feld);

        // Prüfen, ob der Spieler gewonnen hat
        if (pruefe_sieg(feld, spieler)) {
            printf("Yippie Yeah Spieler %c hat gewonnen!\n", spieler);
            break;
        }

        // Prüfen, ob das Feld voll ist
        if (feld_voll(feld)) {
            printf("Unentschieden! Keine freien Felder mehr.\n");
            break;
        }

        // Spieler wechseln
        spieler = (spieler == 'X') ? 'O' : 'X';
    }

    return 0;
}
