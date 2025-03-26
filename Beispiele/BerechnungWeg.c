 /*
Projekt: Berechnung Weg
Autor: Michael Good
Datum: 11.10.2024
Version: 0.1
*/

#include <stdio.h>

int main() {

float watt = 0;             //Leistung in Watt
float masse = 0;            //Kilogramm
float weg = 0;              //Meter
float zeit = 50;            //Sekunden
float geschwindigkeit = 0;  //Sekunden

//Eingabe geschwindikgeit
printf("bitte gib die Geschwindigkeit in Meter pro Sekunde ein:");
scanf("%f", &geschwindigkeit);

//Eingabe Masse
printf("bitte gib die Masse in Kilogramm ein:");
scanf("%f", &masse);

//Eingabe Zeit
printf("bitte gib die Zeit in Sekunden ein:");
scanf("%f", &zeit);

//Eingabe Weg
printf("bitte gib den Weg in Meter ein :");
scanf("%f", &weg);

//Berechnung
geschwindigkeit = weg/zeit;
watt = masse * (geschwindigkeit * geschwindigkeit) / 2;
watt = watt/geschwindigkeit;

//Ausgabe Resultat
printf("\n Der Energieverbrauch in Watt: %f\n", watt);

return 0;
}