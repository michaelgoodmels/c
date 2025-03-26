/*
Projekt:    array
Autor:      Michael Good
Datum:      05.09.2024
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

//Präprozessor initialisieren
#include <stdio.h>

//globale Variablen
int global = 0;

//Funktionsprototyping
int array();

//Hauptaufruf
int main(void){

    array();
    return 0;
}

//Functions
int array(){

    int zahlen [5];
    int gewinnzahlen [] = {3, 27, 35, 6, 15};
    int lottozahlen [5] = {5, 27, 32 , 48, 72};

    lottozahlen[2] = 23;

    printf("%d\n", lottozahlen[2]);

    return 0;
}
