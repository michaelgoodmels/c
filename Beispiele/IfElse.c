/*
########################################################################################################################
# Project: If-Else                                                                                            #
# autor: Michael Good                                                                                                  #
# date: 13.10.2024                                                                                                     #
# version: 0.0.1                                                                                                       #
# contact: michael.good@bzbs.ch                                                                                        #
########################################################################################################################
*/

/*
Typcasting: In den Funktionen rechteckFlaeche und kreisFlaeche wird das Typcasting verwendet, um sicherzustellen, dass die Berechnungen im float-Format durchgeführt werden, was die Genauigkeit bei der Berechnung der Fläche verbessert.
Eingabe: Das Programm fragt den Benutzer nach der Breite und Höhe eines Rechtecks sowie dem Radius eines Kreises und berechnet die entsprechenden Flächen.
Mathematische Konstante: M_PI ist eine Konstante aus der math.h-Bibliothek, die den Wert von π (Pi) repräsentiert.
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
int IfElse();

//Main Program
int main(void) {

    //Endlosschleife
    while(1){
     IfElse();
        }
    return 0;
}

//functions
int IfElse(){

        int zahl;

        printf("Gib eine Zahl ein (1-10): ");
        scanf("%d", &zahl);

        if (zahl == 1) {
            printf("Du hast die Eins gewaehlt! Der Beginn von allem!\n");
        } else if (zahl == 2) {
            printf("Zwei? Super! Du bist schon auf dem Weg zur grossen Entscheidung!\n");
        } else if (zahl == 3) {
            printf("Drei ist eine magische Zahl! Denk daran, alles in Dreiergruppen zu tun!\n");
        } else if (zahl == 4) {
            printf("Vier, die perfekte Anzahl für eine Pizza! Lass uns feiern!\n");
        } else if (zahl == 5) {
            printf("Fünf Finger an einer Hand – genug, um einen Apfel zu halten!\n");
        } else if (zahl == 6) {
            printf("Sechs ist die Anzahl der Schafe, die man zählen sollte, um einzuschlafen!\n");
        } else if (zahl == 7) {
            printf("Sieben – die Zahl des Gluecks! Vielleicht gewinnst du im Lotto!\n");
        } else if (zahl == 8) {
            printf("Acht – perfekt für die Unendlichkeit! Lass uns ewig feiern!\n");
        } else if (zahl == 9) {
            printf("Neun ist fast zehn! Du bist fast am Ziel!\n");
        } else if (zahl == 10) {
            printf("Zehn! Der Hoehepunkt der Zahlen! Du bist der Koenig!\n");
        } else {
            printf("Oh, das ist keine gueltige Zahl! Vielleicht probierst du es mit einem besseren Zahlenspiel?\n");
        }

    return 0;
}