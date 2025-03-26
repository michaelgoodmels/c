/*
Projekt:    for
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
int FuncFor();

//Hauptaufruf
int main(void){
  FuncFor();
  return 0;
  }

//Functions
  int FuncFor(){

    int i, k = 0;
    for(i = 1; i < 101; i++)
      k += i;
      printf("%d", k);
      getchar();
      return 0;
    }