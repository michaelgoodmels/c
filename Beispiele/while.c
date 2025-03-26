/*
Projekt:    while
Autor:      Michael Good
Datum:      05.09.2024
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

//Präprozessor initialisieren
#include <stdio.h>

//Hauptprogramm
int main(void){

  int i = 0;
  int z = 65;

  //69 entspricht ASCII E
  while(z != 69){

    i++;
    printf("Durchlauf: i = %d\n", i);
    printf("Beenden mit E \n");
    printf("Ihre Wahl: ");

    z = getchar(); //erwartet Eingabe von Tastatur
    fflush(stdin); //Zeichen im Puffer löschen
    }
  return 0;
  }
