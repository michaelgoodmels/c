/*
Projekt:    continue
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
int FuncContinue();

//Hauptaufruf
int main(void){

    FuncContinue();
    return 0;
}

//Functions
int FuncContinue(){

    int i;

    for(i = 1; i < 20; i++)
      {
      if(i % 2 == 0)
        continue;
      printf("aktuelle Zahl ist: %d\n", i);
      }
    getchar();
    return 0;
}