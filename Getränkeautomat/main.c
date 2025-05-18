#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>  // fuer usleep (Linux/macOS). Unter Windows:
#include <windows.h>


typedef enum {
    STATE_START,
    STATE_GET_DRINK_CHOICE,
    STATE_GET_OPTIONS,
    STATE_GET_AMOUNT,
    STATE_PAYMENT,
    STATE_DISPENSE,
    STATE_EXIT
} VendingState;

typedef struct {
    int id;
    char name[30];
    float price;
    int needsOptions; // 1 = z.B. Kaffee oder Tee, 0 = einfache Getraenke
} Drink;

Drink drinkList[] = {
    {1, "Wasser", 0.50f, 0},
    {2, "Limonade", 1.00f, 0},
    {3, "Bier", 2.00f, 0},
    {4, "Red Bull", 2.50f, 0},
    {5, "Rivella", 2.00f, 0},
    {6, "Tee", 1.50f, 1},
    {7, "Kaffee", 1.80f, 1}
};

int sorte = 0;
int menge = 1;
float preis = 0.0f;
char optionZucker[10] = "";
char optionMilch[10] = "";

void printDrinkOptions() {
    printf("Waehlen Sie Ihr Getraenk aus:\n");
    for (int i = 0; i < sizeof(drinkList)/sizeof(drinkList[0]); i++) {
        printf("%d) %s (%.2f CHF)\n", drinkList[i].id, drinkList[i].name, drinkList[i].price);
    }
    printf("\nGeben Sie eine Zahl ein: ");
}

void selectDrink() {
    printDrinkOptions();
    scanf("%d", &sorte);

    int valid = 0;
    for (int i = 0; i < sizeof(drinkList)/sizeof(drinkList[0]); i++) {
        if (drinkList[i].id == sorte) {
            preis = drinkList[i].price;
            valid = 1;
            break;
        }
    }

    if (!valid) {
        printf("Ungueltige Auswahl. Es wird Wasser gewaehlt.\n");
        sorte = 1;
        preis = 0.50f;
    }
}

void getDrinkOptions() {
    // Nur bei Tee oder Kaffee Optionen abfragen
    if (sorte != 6 && sorte != 7) {
        strcpy(optionZucker, "");
        strcpy(optionMilch, "");
        return;
    }

    char eingabe[5];
    printf("\nMoechten Sie Zucker? (ja/nein): ");
    scanf("%s", eingabe);
    strcpy(optionZucker, (strcmp(eingabe, "ja") == 0) ? "mit Zucker" : "ohne Zucker");

    printf("Moechten Sie Milch? (ja/nein): ");
    scanf("%s", eingabe);
    strcpy(optionMilch, (strcmp(eingabe, "ja") == 0) ? "mit Milch" : "ohne Milch");
}

void enterAmount() {
    printf("\nGeben Sie die gewuenschte Menge ein: ");
    scanf("%d", &menge);
    if (menge <= 0) {
        printf("Ungueltige Menge. Es wird 1 Flasche angenommen.\n");
        menge = 1;
    }
}

void paymentProcess() {
    printf("\n--- Bezahlvorgang ---\n");
    float zuZahlen = preis * menge;
    float einwurf = 0.0f;

    while (zuZahlen > 0.0f) {
        printf("\nEs fehlen noch %.2f CHF.", zuZahlen);
        printf("\nBitte werfen Sie ein Geldstueck ein: ");
        scanf("%f", &einwurf);

        if (einwurf <= 0) {
            printf("Ungueltiger Betrag. Bitte erneut versuchen.\n");
            continue;
        }

        zuZahlen -= einwurf;
    }

    if (zuZahlen < 0.0f) {
        printf("Wechselgeld: %.2f CHF\n", -zuZahlen);
    }
}

void dispenseDrinks() {
    printf("\n--- Getraenkeausgabe ---\n");

    for (int i = 0; i < sizeof(drinkList)/sizeof(drinkList[0]); i++) {
        if (drinkList[i].id == sorte) {
            for (int j = 0; j < menge; j++) {
                if (drinkList[i].needsOptions) {
                    animateHotDrink(drinkList[i].name, j + 1, menge);
                } else {
                    printf("Flasche %d von %d: %s ausgegeben.\n", j + 1, menge, drinkList[i].name);
                }

            }
            break;
        }
    }

    printf("\nVielen Dank, bitte entnehmen Sie Ihre Getraenke.\n");
}

void clearConsole() {
    // Windows-spezifischer Konsolen-Reset durch system call
    system("cls");
}

void animateHotDrink(const char* drinkName, int tasseNummer, int gesamt) {
    const char* steamFrames[] = {
        "    (  )  ",
        "   (    ) ",
        "  (      )",
        "   (    ) ",
        "    (  )  ",
    };

    const char* cup[] = {
        "     ____ ",
        "    (____)",
        "    (____)  ~~~",
        "    |    |",
        "    |____|",
    };

    printf("\nTasse %d von %d: %s (%s, %s)", tasseNummer, gesamt, drinkName, optionZucker, optionMilch);
    printf("\nBereite heisses Getraenk vor...\n");

    for (int frame = 0; frame < 10; ++frame) {
        clearConsole();
        printf("Getraenke Automat v0.4 (CHF Edition)\n\n");

        // Dampfwolke oben
        printf("%s\n", steamFrames[frame % 5]);

        // Tasse darunter
        for (int i = 0; i < 5; ++i) {
            printf("%s\n", cup[i]);
        }

        Sleep(300);  // 300ms Pause
    }

    printf("\n%s ist fertig! Bitte entnehmen Sie Ihre Tasse.\n", drinkName);
}



int main() {
    VendingState state = STATE_START;

    printf("Getraenke Automat v0.4 (CHF Edition)\n\n");

    while (state != STATE_EXIT) {
        switch (state) {
            case STATE_START:
                state = STATE_GET_DRINK_CHOICE;
                break;
            case STATE_GET_DRINK_CHOICE:
                selectDrink();
                state = STATE_GET_OPTIONS;
                break;
            case STATE_GET_OPTIONS:
                getDrinkOptions();
                state = STATE_GET_AMOUNT;
                break;
            case STATE_GET_AMOUNT:
                enterAmount();
                state = STATE_PAYMENT;
                break;
            case STATE_PAYMENT:
                paymentProcess();
                state = STATE_DISPENSE;
                break;
            case STATE_DISPENSE:
                dispenseDrinks();
                state = STATE_EXIT;
                break;
            default:
                state = STATE_EXIT;
                break;
        }
    }

    return 0;
}
