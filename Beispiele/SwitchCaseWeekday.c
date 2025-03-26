/*
Project: SwitchCase
 author: Michael Good
 date: 10.10.2024
 version: 0.0.1
 contact: michael.good@bzbs.ch
 */

//includes
#include <stdio.h>
#include <string.h>

//global Variables
int tag = 0;

//Function Prototyping
void SwitchCase();

//Main Program
int main(void) {
    while(1) {
        SwitchCase();
        //return 0;
    }
}

//Functions
void SwitchCase(){

    //local Variables in Function
    char day[20];  // To store user input

    printf("\n gib den Tag ein, den du sehen moechtest: ");
    scanf("%s", day);

    // Convert the input string to a corresponding integer
    if (strcmp(day, "Montag") == 0 || strcmp(day, "montag") == 0) {
        tag = 1;
    } else if (strcmp(day, "Dienstag") == 0 || strcmp(day, "dienstag") == 0) {
        tag = 2;
    } else if (strcmp(day, "Mittwoch") == 0 || strcmp(day, "mittwoch") == 0) {
        tag = 3;
    } else if (strcmp(day, "Donnerstag") == 0 || strcmp(day, "donnerstag") == 0) {
        tag = 4;
    } else if (strcmp(day, "Freitag") == 0 || strcmp(day, "freitag") == 0) {
        tag = 5;
    } else if (strcmp(day, "Samstag") == 0 || strcmp(day, "samstag") == 0) {
        tag = 6;
    } else if (strcmp(day, "Sonntag") == 0 || strcmp(day, "sonntag") == 0) {
        tag = 7;
    } else {
        tag = 0;  // falscher Tag
    }

    // Use switch-case with the integer 'tag'
    switch (tag) {
        case 1: printf("Dies ist der erste Tag der Woche\n");
        break;
        case 2: printf("Das ist der zweite Tag der Woche\n");
        break;
        case 3: printf("Das ist der dritte Tag der Woche\n");
        break;
        case 4: printf("Das ist der vierte Tag der Woche\n");
        break;
        case 5: printf("Das ist der fuenfte Tag der Woche\n");
        break;
        case 6: printf("Das ist der sechte Tag der Woche\n");
        break;
        case 7: printf("Das ist der siebte Tag der Woche\n");
        break;
        default: printf("Kennst du die Tage der Woche?\n");
        break;
    }
}
