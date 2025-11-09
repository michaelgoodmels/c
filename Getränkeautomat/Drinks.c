#include <stdio.h>
#include <string.h>

// Struktur, die ein Getränk repräsentiert
struct Drink {
    char name[20];
    float price;
    int quantity;
};

// Zustände des Getränkeautomaten
typedef enum {
    STATE_MENU,
    STATE_INSERT_MONEY,
    STATE_SELECT_DRINK,
    STATE_DISPLAY_STATUS,
    STATE_EXIT
} VendingState;

// Initialisiere Getränke
void initializeDrinks(struct Drink vendingMachine[], int size) {
    struct Drink initDrinks[6] = {
        {"Cola", 1.50, 5},
        {"Wasser", 1.00, 10},
        {"Fanta", 1.30, 3},
        {"Sprite", 1.30, 7},
        {"Eistee", 2.00, 4},
        {"Kaffee", 1.80, 6}
    };
    for (int i = 0; i < size; ++i) {
        vendingMachine[i] = initDrinks[i];
    }
}

// Funktion, um den Getränkeautomatenstatus anzuzeigen
void displayStatus(struct Drink vendingMachine[], int numDrinks) {
    printf("\n--- Getränkeautomatenstatus ---\n");
    for (int i = 0; i < numDrinks; ++i) {
        printf("%d. %s - %.2f Euro - Verfügbar: %d\n",
               i + 1,
               vendingMachine[i].name,
               vendingMachine[i].price,
               vendingMachine[i].quantity);
    }
    printf("-------------------------------\n");
}

// Funktion zum Einwerfen von Geld
void insertMoney(float *balance) {
    float amount;
    printf("Guthaben einwerfen (in Euro): ");
    scanf("%f", &amount);
    if (amount > 0) {
        *balance += amount;
        printf("Neues Guthaben: %.2f Euro\n", *balance);
    } else {
        printf("Ungültiger Betrag.\n");
    }
}

// Funktion zum Auswählen und Kaufen eines Getränks
void selectDrink(struct Drink vendingMachine[], int numDrinks, float *balance) {
    int choice;
    displayStatus(vendingMachine, numDrinks);
    printf("Wählen Sie ein Getränk (1-%d): ", numDrinks);
    scanf("%d", &choice);

    if (choice < 1 || choice > numDrinks) {
        printf("Ungültige Auswahl.\n");
        return;
    }

    struct Drink *selected = &vendingMachine[choice - 1];

    if (selected->quantity == 0) {
        printf("Dieses Getränk ist ausverkauft.\n");
        return;
    }

    if (*balance < selected->price) {
        printf("Nicht genug Guthaben. Bitte mehr Geld einwerfen.\n");
        return;
    }

    selected->quantity--;
    *balance -= selected->price;
    printf("Vielen Dank! Sie haben %s gekauft.\n", selected->name);
}

// Menü anzeigen und Zustand bestimmen
VendingState displayMenu() {
    int choice;
    printf("\n--- Menü ---\n");
    printf("1. Guthaben einwerfen\n");
    printf("2. Getränk auswählen\n");
    printf("3. Automatenstatus anzeigen\n");
    printf("4. Beenden\n");
    printf("Ihre Wahl: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: return STATE_INSERT_MONEY;
        case 2: return STATE_SELECT_DRINK;
        case 3: return STATE_DISPLAY_STATUS;
        case 4: return STATE_EXIT;
        default:
            printf("Ungültige Auswahl.\n");
            return STATE_MENU;
    }
}

int main() {
    struct Drink vendingMachine[6];
    initializeDrinks(vendingMachine, 6);

    float balance = 0.0f;
    VendingState state = STATE_MENU;

    while (state != STATE_EXIT) {
        switch (state) {
            case STATE_MENU:
                state = displayMenu();
                break;
            case STATE_INSERT_MONEY:
                insertMoney(&balance);
                state = STATE_MENU;
                break;
            case STATE_SELECT_DRINK:
                selectDrink(vendingMachine, 6, &balance);
                state = STATE_MENU;
                break;
            case STATE_DISPLAY_STATUS:
                displayStatus(vendingMachine, 6);
                state = STATE_MENU;
                break;
            default:
                state = STATE_MENU;
        }
    }

    printf("Programm wird beendet.\n");
    return 0;
}
