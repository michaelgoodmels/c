#include <stdio.h>

// Struktur, die ein Getränk repräsentiert
struct Drink {
    char name[20];
    float price;
    int quantity;
};

// Funktion, um den Getränkeautomatenstatus anzuzeigen
void displayStatus(struct Drink vendingMachine[], int numDrinks) {
    printf("\nGetränkeautomatenstatus:\n");
    for (int i = 0; i < numDrinks; ++i) {
        printf("%d. %s - %.2f Euro - Verfügbar: %d\n", i + 1, vendingMachine[i].name, vendingMachine[i].price, vendingMachine[i].quantity);
    }
    printf("\n");
}

// Funktion zum Auswählen und Kaufen eines Getränks
void selectDrink(struct Drink vendingMachine[], int numDrinks, float *balance) {
    int choice;

    // Anzeige der verfügbaren Getränke
    displayStatus(vendingMachine, numDrinks);

    // Auswahl des Getränks
    printf("Wählen Sie ein Getränk (1-%d): ", numDrinks);
    scanf("%d", &choice);

    // Überprüfung der gültigen Auswahl
    if (choice < 1 || choice > numDrinks) {
        printf("Ungültige Auswahl.\n");
        return;
    }

    // Überprüfung, ob das ausgewählte Getränk verfügbar ist
    if (vendingMachine[choice - 1].quantity == 0) {
        printf("Dieses Getränk ist ausverkauft.\n");
        return;
    }

    // Überprüfung des Guthabens
    if (*balance < vendingMachine[choice - 1].price) {
        printf("Nicht genug Guthaben. Bitte mehr Geld einwerfen.\n");
        return;
    }

    // Kauf erfolgreich
    printf("Vielen Dank! Sie haben %s gekauft.\n", vendingMachine[choice - 1].name);

    // Reduzieren Sie die Menge des gekauften Getränks
    vendingMachine[choice - 1].quantity--;

    // Reduzieren Sie das Guthaben um den Preis des gekauften Getränks
    *balance -= vendingMachine[choice - 1].price;
}

int main() {
    // Initialisierung des Getränkeautomaten mit 6 Getränken
    struct Drink vendingMachine[6] = {
        {"Cola", 1.50, 5},
        {"Wasser", 1.00, 10},
        {"Fanta", 1.30, 3},
        {"Sprite", 1.30, 7},
        {"Eistee", 2.00, 4},
        {"Kaffee", 1.80, 6}
    };

    float balance = 0.0; // Initialisiertes Guthaben

    int choice;
    do {
        // Menü anzeigen
        printf("\nMenü:\n");
        printf("1. Guthaben einwerfen\n");
        printf("2. Getränk auswählen\n");
        printf("3. Getränkeautomatenstatus anzeigen\n");
        printf("4. Beenden\n");
        printf("Ihre Wahl: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Guthaben einwerfen
                printf("Guthaben einwerfen (in Euro): ");
                float amount;
                scanf("%f", &amount);
                balance += amount;
                printf("Neues Guthaben: %.2f Euro\n", balance);
                break;
            case 2:
                // Getränk auswählen und kaufen
                selectDrink(vendingMachine, 6, &balance);
                break;
            case 3:
                // Getränkeautomatenstatus anzeigen
                displayStatus(vendingMachine, 6);
                break;
            case 4:
                // Beenden
                printf("Programm wird beendet.\n");
                break;
            default:
                printf("Ungültige Auswahl. Bitte versuchen Sie es erneut.\n");
        }

    } while (choice != 4);

    return 0;
}
