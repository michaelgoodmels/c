/*
Projekt:    do-while
Autor:      Michael Good
Datum:      05.09.2024
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

//Präprozessor initialisieren
#include<stdio.h>

//globale Variablen
int global = 0;

//Funktionsprototyping
int menu();

//Hauptprogramm
int main(void){

  int i;
  do{
    i = menu();
    printf("Das Hauptprogramm wuerde Menuepunkt %d abarbeiten", i);
    }

  while((i > 0) && (i < 5));
  return 0;
}

//Funktionsaufrufe
int menu(void){

  int m;

  printf("\n\tMenue\n");
  printf("\t=====\n\n");
  printf("Addition..........1\n");
  printf("Subtraktion.......2\n");
  printf("Multiplikation....3\n");
  printf("Division..........4\n");
  printf("ENDE..............Nicht 1 bis 4\n\n");
  printf("Ihre Wahl: ");
  scanf("%d", &m);
  return m;
}