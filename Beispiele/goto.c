/*
Projekt:    goto
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
int FuncGoTo();

//Hauptaufruf
int main(void){

    FuncGoTo();
    return 0;
}

//Functions
int FuncGoTo(){

    int i;

    goto Eingabe;
    Hinweis: printf("Es gibt nur die Noten von 1 - 6 !!\n\n");
    Eingabe: printf("Bitte geben Sie Ihre Noten ein [1 - 6]: ");

    scanf("%d", &i);

    if((i < 1) || (i > 6))

        goto Hinweis;

    fflush(stdin);
    getchar();
    return 0;
}
