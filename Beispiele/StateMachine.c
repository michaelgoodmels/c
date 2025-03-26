#include <stdio.h>

// Definition der Ampelzustände
typedef enum {
    ROT,
    GELB,
    GRUEN
} SignalZustand;

// Struktur, die die Ampel und ihren Zustand repräsentiert
typedef struct {
    int id;                  // Ampel-ID (1 bis 4)
    SignalZustand zustand;   // Aktueller Zustand der Ampel
} Ampel;

// Funktion, die den Zustand einer Ampel ändert
SignalZustand wechsleZustand(SignalZustand aktuellerZustand) {
    switch (aktuellerZustand) {
        case ROT:
            return GRUEN;
        case GELB:
            return ROT;
        case GRUEN:
            return GELB;
        default:
            return ROT; // Fallback
    }
}

// Funktion, die den Zustand einer einzelnen Ampel anzeigt
void zeigeAmpelStatus(Ampel* a) {
    printf("Ampel %d: ", a->id);
    switch (a->zustand) {
        case ROT:
            printf("ROT\n");
            break;
        case GELB:
            printf("GELB\n");
            break;
        case GRUEN:
            printf("GRUEN\n");
            break;
    }
}

// Funktion, die den Zustand aller Ampeln aktualisiert
void updateAlleAmpeln(Ampel* ampeln, int anzahlAmpeln) {
    for (int i = 0; i < anzahlAmpeln; i++) {
        ampeln[i].zustand = wechsleZustand(ampeln[i].zustand);
    }
}

// Funktion, die den initialen Zustand der Ampeln festlegt
void initialisiereAmpeln(Ampel* ampeln, int anzahlAmpeln) {
    for (int i = 0; i < anzahlAmpeln; i++) {
        ampeln[i].id = i + 1;  // Ampel-ID von 1 bis 4
        ampeln[i].zustand = ROT;  // Anfangszustand ist ROT
    }
}

int main() {
    // Initialisierung der 4 Ampeln
    Ampel ampeln[4];
    int anzahlAmpeln = 4;

    initialisiereAmpeln(ampeln, anzahlAmpeln);

    // Endlosschleife für die State Machine
    while (1) {
        // Status der Ampeln anzeigen
        for (int i = 0; i < anzahlAmpeln; i++) {
            zeigeAmpelStatus(&ampeln[i]);
        }

        // Alle Ampeln aktualisieren (Zustände wechseln)
        updateAlleAmpeln(ampeln, anzahlAmpeln);

        // Warten für 1 Sekunde
        sleep(1);
    }

    return 0;
}
