/*
Projekt:    Getränkeautomat Struct6
Autor:      Michael Good
Datum:      19.11.2025
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

//Präprozessor initialisieren
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>   // Für sleep() – Unix/Linux
// #include <windows.h> // Für Windows: Sleep(1000); statt sleep(1);

#define CLEAR_SCREEN() printf("\033[H\033[J")  // ANSI-Clear (Linux/macOS)
// Für Windows: system("cls");

struct Getraenk {
    char name[100];
    float preis;
};

void zubereitung_animation(const char* getraenk) {
    printf("\n%s wird zubereitet", getraenk);
    fflush(stdout);
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);  // 1 Sekunde warten
    }
    printf(" Fertig!\n\n");
}

int main() {
    struct Getraenk mineral = {"Mineral", 2.00};
    struct Getraenk apfelsaft = {"Apfelsaft", 2.50};
    struct Getraenk rivella = {"Rivella", 2.50};
    struct Getraenk sinalco = {"Sinalco", 2.50};
    struct Getraenk tee = {"Tee", 3.00};
    struct Getraenk kaffee = {"Kaffee", 3.00};
    struct Getraenk espresso = {"Espresso", 3.50};
    struct Getraenk latte = {"Latte Macchiato", 4.00};

    struct Getraenk ausgewaehlt;
    char zucker[20], milch[20];
    int getraenk_wahl, kaffee_variante, bezahlung;
    float bezahlt, rueckgeld, fehlend;
    char eingabe[10];

    printf("=== WILLKOMMEN AM GETRÄNKEAUTOMATEN ===\n");
    sleep(1);

    while (1) {
        bezahlt = 0.0;
        strcpy(ausgewaehlt.name, "");

        // --- Getränk auswählen ---
        printf("Waehlen Sie Ihr Getraenk (oder '0' / 'q' zum Beenden):\n");
        printf("1: Mineral         (%.2f CHF)\n", mineral.preis);
        printf("2: Apfelsaft       (%.2f CHF)\n", apfelsaft.preis);
        printf("3: Rivella         (%.2f CHF)\n", rivella.preis);
        printf("4: Sinalco         (%.2f CHF)\n", sinalco.preis);
        printf("5: Tee             (%.2f CHF)\n", tee.preis);
        printf("6: Kaffee          (ab %.2f CHF)\n", kaffee.preis);
        printf("Ihre Wahl: ");
        scanf("%s", eingabe);

        if (eingabe[0] == '0' || tolower(eingabe[0]) == 'q') {
            printf("\nVielen Dank! Auf Wiedersehen!\n");
            return 0;
        }

        getraenk_wahl = eingabe[0] - '0';
        if (getraenk_wahl < 1 || getraenk_wahl > 6) {
            printf("Ungueltige Auswahl. Bitte erneut versuchen.\n\n");
            continue;
        }

        switch (getraenk_wahl) {
            case 1: ausgewaehlt = mineral; break;
            case 2: ausgewaehlt = apfelsaft; break;
            case 3: ausgewaehlt = rivella; break;
            case 4: ausgewaehlt = sinalco; break;
            case 5: ausgewaehlt = tee; break;
            case 6:
                printf("\nWelche Kaffeesorte?\n");
                printf("1: Espresso         (%.2f CHF)\n", espresso.preis);
                printf("2: Latte Macchiato  (%.2f CHF)\n", latte.preis);
                printf("3: Normaler Kaffee  (%.2f CHF)\n", kaffee.preis);
                printf("Ihre Wahl (1-3): ");
                scanf("%d", &kaffee_variante);

                switch (kaffee_variante) {
                    case 1: ausgewaehlt = espresso; break;
                    case 2: ausgewaehlt = latte; break;
                    case 3: ausgewaehlt = kaffee; break;
                    default:
                        printf("Ungueltige Sorte. Zurueck zum Start.\n\n");
                        continue;
                }
                break;
        }

        // --- Zucker & Milch abfragen ---
        if (getraenk_wahl == 5) {  // Tee
            printf("\nTee mit oder ohne Zucker? (mit/ohne): ");
            scanf("%s", zucker);
            if (strcmp(zucker, "mit") == 0) {
                strcat(ausgewaehlt.name, " mit Zucker");
            } else {
                strcat(ausgewaehlt.name, " ohne Zucker");
            }
        }
        else if (getraenk_wahl == 6) {  // Kaffee
            printf("\nKaffee mit oder ohne Zucker? (mit/ohne): ");
            scanf("%s", zucker);
            printf("Mit oder ohne Milch? (mit/ohne): ");
            scanf("%s", milch);

            // Basisname
            strcpy(ausgewaehlt.name, ausgewaehlt.name);  // z. B. "Kaffee"

            // Zucker
            if (strcmp(zucker, "mit") == 0) {
                strcat(ausgewaehlt.name, " mit Zucker");
            } else {
                strcat(ausgewaehlt.name, " ohne Zucker");
            }

            // Milch
            if (strcmp(milch, "mit") == 0) {
                strcat(ausgewaehlt.name, " mit Milch");
            } else {
                strcat(ausgewaehlt.name, " ohne Milch");
            }
        }

        // --- Bestellung anzeigen ---
        printf("\n--- BESTELLUNG ---\n");
        printf("Getraenk: %s\n", ausgewaehlt.name);
        printf("Preis:    %.2f CHF\n\n", ausgewaehlt.preis);

        // --- Bezahlung ---
        printf("Zahlungsmethode:\n");
        printf("1: Bar (mit Nachzahlung)\n");
        printf("2: Twint\n");
        printf("3: Karte\n");
        printf("Ihre Wahl (1-3): ");
        scanf("%d", &bezahlung);

        if (bezahlung == 2 || bezahlung == 3) {
            printf("Bezahlung per %s erfolgreich.\n", (bezahlung == 2) ? "Twint" : "Karte");
        }
        else if (bezahlung == 1) {
            while (bezahlt < ausgewaehlt.preis) {
                fehlend = ausgewaehlt.preis - bezahlt;
                if (bezahlt > 0.0) {
                    printf("\nZu wenig! Es fehlen noch: %.2f CHF\n", fehlend);
                }
                printf("Einwurf (mind. %.2f CHF): ", fehlend);
                float einzahlung;
                if (scanf("%f", &einzahlung) != 1 || einzahlung <= 0) {
                    printf("Ungueltiger Betrag. Transaktion abgebrochen.\n\n");
                    continue;
                }
                bezahlt += einzahlung;
            }
            rueckgeld = bezahlt - ausgewaehlt.preis;
            if (rueckgeld > 0) {
                printf("Rueckgeld: %.2f CHF\n", rueckgeld);
            }
        }
        else {
            printf("Ungueltige Methode. Zurueck zum Start.\n\n");
            continue;
        }

        // --- Zubereitungsanimation ---
        zubereitung_animation(ausgewaehlt.name);

        // --- Abschluss ---
        printf("Danke! Geniessen Sie Ihr %s.\n", ausgewaehlt.name);
        printf("Besuchen Sie uns bald wieder!\n");
        printf("-----------------------------------------\n\n");

        sleep(1);
    }

    return 0;
}