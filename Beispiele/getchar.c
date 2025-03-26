 /*
Projekt: getchar
Autor: Michael Good
Datum: 11.10.2024
Version: 0.1
*/

//Präprozessor initialisieren
#include <stdio.h>

//globale Variablen
int global = 0;

//Funktionsprototyping
int GetChar();

//Hauptaufruf
int main(void){

    GetChar();
    return 0;
}

//Functions
int GetChar(){

int antwort;
printf("Bitte lesen Sie diese Zeile!\n(Weiter mit der ENTER Taste!)\n");

getchar(); //wartet auf eine Tastatureingabe

printf("Das ist der weitere Text.... (Weiter mit 'einer beliebigen Taste')\n(Weiter mit der ENTER Taste!)\n");
    antwort = getchar();

    getchar(); //wartet auf eine Tastatureingabe

    printf("Die Antwort war %c", antwort);

    getchar(); //wartet auf eine Tastatureingabe
    return 0;
}
