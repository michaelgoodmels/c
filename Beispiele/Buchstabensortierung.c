/*
Project:  Array
 author:  Michael Good
 date:    25.11.2024
 version: 0.0.1
 contact: michael.good@bzbs.ch
 */

//includes
#include <stdio.h>

//Main Program
int main(void) {

  int index;
  int nummer;
  int ok;
  char buchstabe;
  char liste[20];
  int max = 5;

  printf("Bitte geben Sie die Liste der Buchstben ein: \n");
  for (index = 0; index < max; index++) {
    scanf("%c", &liste[index]);
        if(liste[index] < 65)
          index --;
    }
    nummer = 0;
    do{
      ok = 0;
      nummer++;
      for (index = 0; index < (max - nummer); index++)
      {
            if(liste[index] > liste[index + 1])
            {
              ok = 1;
              buchstabe = liste[index];
              liste[index] = liste[index + 1];
              liste[index + 1] = buchstabe;
              };
            }
      }

      while(ok == 1);
      printf("Sortierung Liste: \n");
      for (index = 0; index < max; index++)
        printf("%c", liste[index]);
      printf("\n Sortierung erfolgt nach %d Durchlaeufen.", nummer);
      getchar();
      fflush(stdin);
      getchar();
      return 0;
}

