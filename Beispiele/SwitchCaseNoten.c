/*
Project: SwitchCase Noten
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
int SwitchCaseNoten();

//Main Program
int main(void){
    SwitchCaseNoten();
    return 0;
}

//Functions
int SwitchCaseNoten(){

    //local Variables in Function
    int i, a;
    do{
       a = 0;
       printf("Please enter a note from 1 - 6: ");
       scanf("%d", &i);

    switch (i){
        case 1: printf("it's a deficient note");
                a = 1;
                break;
        case 2: printf("it's a poor note");
                a = 1;
                break;
        case 3: printf("it's a sufficient note");
                a = 1;
                break;
        case 4: printf("it's a satisfactory note");
                a = 1;
                break;
        case 5: printf("it's a good note!");
                a = 1;
                break;
        case 6: printf("it's a verry good note!");
                a = 1;
                break;
        default: printf("this value isn't in range of 1 to 6");
                break;
    }
    getchar();
}
while(a == 0);
fflush(stdin);
getchar();
return 0;
}