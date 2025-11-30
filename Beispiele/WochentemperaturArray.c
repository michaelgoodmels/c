/*
Projekt:    Wochentemperatur Array
Autor:      Michael Good
Datum:      29.11.2025
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

#include <stdio.h>

int main() {
    float temperatur[7] = {2.1, 3.4, 5.0, 1.8, -0.5, 0.0, 4.2};
    int n = 7;
    float summe = 0;

    // Mittelwert berechnen
    for (int i = 0; i < n; i++) {
        summe += temperatur[i];
    }
    float durchschnitt = summe / n;
    printf("Durchschnitt: %.2f %cC\n", durchschnitt, 248);

    // --- Median berechnen ---
    // Kopie des Arrays erstellen, damit Originalwerte erhalten bleiben
    float temp_sorted[7];
    for (int i = 0; i < n; i++) {
        temp_sorted[i] = temperatur[i];
    }

    // Einfaches Bubble Sort zum Sortieren
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp_sorted[j] > temp_sorted[j + 1]) {
                float tmp = temp_sorted[j];
                temp_sorted[j] = temp_sorted[j + 1];
                temp_sorted[j + 1] = tmp;
            }
        }
    }

    float median;
    if (n % 2 == 1) {  // ungerade Anzahl
        median = temp_sorted[n / 2];
    } else {           // gerade Anzahl
        median = (temp_sorted[n/2 - 1] + temp_sorted[n/2]) / 2;
    }

    printf("Median: %.2f %cC\n", median, 248);

    return 0;
}

