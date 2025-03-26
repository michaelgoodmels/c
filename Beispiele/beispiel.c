/*
########################################################################################################################
# Project: Beispiel                                                                                         #
# autor: Mustervorname Musternachname                                                                                               #
# date: 13.10.2024                                                                                                     #
# version: 0.0.1                                                                                                       #
# contact: elon.musk@x.com                                                                                      #
########################################################################################################################
*/

/*
Kommentar
*/

//includes/präprozessor
#include <stdio.h>
#include <math.h>

//global Variables
int GlobalVariableInt = 0;
float GlobalVariableFloat = 0.0;
char GlobalVariableCharChar = ' ';
char GlobalVariable[10] = {0, 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};

//prototyping
int Funktion();

//Main Program
int main(void) {

    //Endlosschleife
    while(1){
        Funktion();
    }
    return 0;
}

//functions
int Funktion(){

    int Muster;

    printf("Hier kommt was auf der Konsole raus ");
    scanf("%d", &Muster);

    if (Muster == 1) {
        printf("Muster: 1\n");
    } else if (Muster == 2) {
        printf("Muster: 2\n");
    } else {
        printf("Muster: ?\n");
    }

    return 0;
}