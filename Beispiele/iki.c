// Projektinformationen:
/*
Projektname: If-else uebung
Created:        21.10.2024  11:23
Author:         Isam Ajdari
Version:        V0.1
*/


#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    int zahl;

    while (1)
    {
        // Benutzer auffordern eine Zahl einzugeben 1-10
        printf("Guten Tag, gebe eine Zahl von 1-10 ein\n");
        scanf("%d", &zahl );

        // Wenn eine Zahl 1-10 eingegeben wird = indivduelle Nachricht
        if (zahl >= 1 && zahl <= 10)

            switch (zahl) {

            case 1:
                printf("Die 1 ist ein guter Anfang für diese Reise\n");
            break;

            case 2:
                printf("Die 2 ist ideal für dich\n");
            break;

            case 3:
                printf("Die 3 ist eine Glückszahl\n");
            break;

            case 4:
                printf("Die Nummer 4 ist eine Pechzahl\n");
            break;

            case 5:
                printf("Die 5 bedeutet du gewinnst im Lott\n");
            break;

            case 6:
                printf("Die 6 hat eine wunderschöne Kurve\n");
            break;

            case 7:
                printf("Die 7 wie Ronaldo suiiiii\n");
            break;

            case 8:
                printf("Die 8 hat eine Kurve mehr als die 6 :)\n");
            break;

            case 9:
                printf("Die 9 bedeutet das es Morgen ein teurer Tag wird\n");
            break;

            case 10:
                printf("Das Ende liegt nahe\n");
            break;

        }
        // Wen keine Zahl von 1-10 eingegebn wird

        else
        {
            printf("Diese Zahl befindet sich nicht zwischen 1-10\n");
        }

    }

return 0;
}


