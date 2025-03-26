/*
 Project: SwitchCaseDay
 autor: Michael Good
 date: 10.10.2024
 version: 0.0.1
 contact: michael.good@bzbs.ch
 */

//includes
#include <stdio.h>

//global Variables
    int tag = 0;

//Function Prototyping
void SwitchCase();

//Main Program
 int main(void){
   SwitchCase();
   return 0;
 }

 //Functions
void SwitchCase(){

//local Variables in Function
  int day;

  printf("\npleace give the day you want see:");
  scanf("%d", &day);

    switch (day){
        case 01: printf("It's a Monday\n: ");
        break;
        case 02: printf("It's a Tuesday\n: ");
        break;
        case 03: printf("It's a Wednesday\n: ");
        break;
        case 04: printf("It's a Thursday\n: ");
        break;
        case 05: printf("It's a Friday\n: ");
        break;
        case 06: printf("It's a Saturday\n: ");
        break;
        case 07: printf("It's a Sunday\n: ");
        break;
        default: printf("You entered an invalid day");
    }
}