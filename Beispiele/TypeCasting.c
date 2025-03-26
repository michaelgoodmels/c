/*
########################################################################################################################
# Project: TypeCasting                                                                                                 #
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
int TypeCasting();

//Main Program
int main(void){

    TypeCasting();

    return 0;
}

//functions
int TypeCasting(){

    int breite, hoehe, radius;

    // Funktion zur Berechnung der Fläche eines Rechtecks
    float rechteckFlaeche(int breite, int hoehe) {
        return (float)breite * (float)hoehe; // Typcasting zu float
    }

    // Funktion zur Berechnung der Fläche eines Kreises
    float kreisFlaeche(int radius) {
        return (float)(M_PI * radius * radius); // Typcasting zu float
    }

        // Eingabe für Rechteck
        printf("Geben Sie die Breite des Rechtecks ein: ");
        scanf("%d", &breite);
        printf("Geben Sie die Hoehe des Rechtecks ein: ");
        scanf("%d", &hoehe);

        // Fläche des Rechtecks berechnen
        float rechteckArea = rechteckFlaeche(breite, hoehe);
        printf("Die Flaeche des Rechtecks betraegt: %.2f\n", rechteckArea);

        // Eingabe für Kreis
        printf("Geben Sie den Radius des Kreises ein: ");
        scanf("%d", &radius);

        // Fläche des Kreises berechnen
        float kreisArea = kreisFlaeche(radius);
        printf("Die Flaeche des Kreises betraegt: %.2f\n", kreisArea);

    return 0;
}