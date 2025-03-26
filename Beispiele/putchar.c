 /*
Projekt: PutChar
Autor: Michael Good
Datum: 11.10.2024
Version: 0.1
*/

//Präprozessor initialisieren
#include <stdio.h>

//globale Variablen
int global = 0;

//Funktionsprototyping
int PutChar();

//Hauptaufruf
int main(void){

    PutChar();
    return 0;
}

//Functions
int PutChar(){

    char z1;
    z1 = 'A';

    putchar(z1);
    putchar(' ');
    putchar('5');
    putchar(' ');
    putchar(40); //(
    putchar(41); //)
    putchar(' ');
    putchar(38); //&
    putchar(' ');
    putchar(40); //(
    putchar(41); //)
    putchar(' ');
    putchar('6');
    putchar(' ');
    getchar();
    return 0;
}
