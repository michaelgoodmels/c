 /*
Projekt: Berechnung Weg Kaffee
Autor: Michael Good
Datum: 20.11.2023
Version: 0.1
*/

#include <stdio.h>

int main() {

float watt;
float masse = 72.2;    //Kilogramm
float weg = 25;      //Meter
float zeit = 50;     //Sekunden
float geschwindigkeit;

geschwindigkeit = weg/zeit;
watt = masse * (geschwindigkeit * geschwindigkeit) / 2;
watt = watt/geschwindigkeit;

printf("Der Energieverbrauch in Watt: %f\n", watt);

return 0;
}
