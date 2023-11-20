 /*
Projekt: Berechnung Weg Kaffee Funktionsorientiert
Autor: Michael Good
Datum: 20.11.2023
Version: 0.1
*/

#include <stdio.h>
#include <math.h>

// globale Variablen
float masse = 72.2;    // Kilogramm
float weg = 25;         // Meter
float zeit = 50;        // Sekunden

// Funktionsprototyping
float BerechnungWegKaffee(float masse, float weg, float zeit);

// main
int main() {
    float watt, geschwindigkeit;

    // Funktionsaufruf
    watt = BerechnungWegKaffee(masse, weg, zeit);

    // Ausgabe
    printf("Der Energieverbrauch in Watt: %f\n", watt);

    return 0;
}

// Funktionsdefinition
float BerechnungWegKaffee(float masse, float weg, float zeit) {
    float geschwindigkeit = weg / zeit;
    float watt = masse * (geschwindigkeit * geschwindigkeit) / 2;
    watt = watt / geschwindigkeit;

    return watt;
}
