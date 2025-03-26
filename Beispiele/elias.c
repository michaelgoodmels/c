//Projektinformationen:
/*
Projektname:    Taschenrechner
Created:        21.10.2024 20:03:00
Author:         Elias Zimmermann
Version:        V0.1
*/

//Bilbliotheken implementieren
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Hauptfunktion
int main(){
    int zahl;

    while (1) { // Unendliche Schleife
        // Aufforderung eine Zahl einzugeben
        printf("Bitte geben sie eine Zahl zwischen 1 und 10 ein: ");
        scanf("%d" , &zahl);

        // Überprüfen ob Zahl zwischen 1 und 10 ist.
        if (zahl >= 1 && zahl <= 10) {
            // Nachricht für Zahl
            switch (zahl) {
                case 1:
                    printf("Der Anfang...\n");
                    break;

                case 2:
                    printf("Doppelt hält besser.\n");
                    break;

                case 3:
                    printf("Die Dreifaltigkeit.\n");
                    break;

                case 4:
                    printf("Vierfach hält noch besser\n");
                    break;

                case 5:
                    printf("Die Haelfte.\n");
                    break;

                case 6:
                    printf("Ist in Zeitrechnungen wichtig.\n");
                    break;

                case 7:
                    printf("Die Glückszahl.\n");
                    break;

                case 8:
                    printf("Noch zwei mehr bis zu Zehn.\n");
                    break;

                case 9:
                    printf("Nicht ganz Zehn.\n");
                    break;

                case 10:
                    printf("Eine Zahl mit der man recht einfach rechnen kann.\n");
                    break;
            }
        } else {
            // Ungültige Eingabe
            printf("Die gewählte Zahl ist nicht zwischen 1 und 10, keine Kommazahlen!\n");
        }
    }

    return 0;
}