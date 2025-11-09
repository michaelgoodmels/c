#include <stdio.h>
#include <stdlib.h>

// Struktur für ein Getränk
typedef struct {
    char name[20];
    float price;
} Drink;

// Funktion zur Anzeige der Getränke
void displayDrinks(Drink drinks[], int size) {
    printf("\nGetränkeautomat - Verfügbare Getränke:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - %.2f EUR\n", i + 1, drinks[i].name, drinks[i].price);
    }
    printf("----------------------------------------\n");
}

// Funktion zur Verarbeitung der Bezahlung
float processPayment(float price) {
    float insertedMoney;
    printf("Preis: %.2f EUR. Bitte Geld einwerfen: ", price);
    scanf("%f", &insertedMoney);

    while (insertedMoney < price) {
        printf("Unzureichender Betrag! Noch %.2f EUR benötigt: ", price - insertedMoney);
        float moreMoney;
        scanf("%f", &moreMoney);
        insertedMoney += moreMoney;
    }

    return insertedMoney;
}

// Funktion zur Berechnung und Ausgabe des Wechselgeldes
void returnChange(float insertedMoney, float price) {
    if (insertedMoney > price) {
        printf("Wechselgeld: %.2f EUR\n", insertedMoney - price);
    }
}

int main() {
    // Getränkeliste
    Drink drinks[] = {
        {"Cola", 1.50},
        {"Wasser", 1.00},
        {"Saft", 2.00},
        {"Eistee", 1.80}
    };
    int numDrinks = sizeof(drinks) / sizeof(drinks[0]);

    int choice;
    float insertedMoney;

    while (1) {
        // Getränke anzeigen
        displayDrinks(drinks, numDrinks);

        // Benutzereingabe für Auswahl
        printf("Bitte wählen Sie ein Getränk (1-%d, 0 zum Beenden): ", numDrinks);
        scanf("%d", &choice);

        // Programm beenden
        if (choice == 0) {
            printf("Vielen Dank! Auf Wiedersehen!\n");
            break;
        }

        // Überprüfen, ob die Auswahl gültig ist
        if (choice < 1 || choice > numDrinks) {
            printf("Ungültige Auswahl! Bitte erneut versuchen.\n");
            continue;
        }

        // Ausgewähltes Getränk und Preis
        Drink selectedDrink = drinks[choice - 1];
        printf("Sie haben %s gewählt.\n", selectedDrink.name);

        // Zahlung verarbeiten
        insertedMoney = processPayment(selectedDrink.price);

        // Wechselgeld zurückgeben
        returnChange(insertedMoney, selectedDrink.price);

        // Bestätigung der Ausgabe
        printf("%s wird ausgegeben. Genießen Sie Ihr Getränk!\n", selectedDrink.name);
    }

    return 0;
}//
// Created by micha on 24.09.2025.
//
