/*
Projekt:    bmi
Autor:      Michael Good
Datum:      05.09.2024
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

#include <stdio.h>

// Funktionsprototypen
double calculate_bmi(double weight, double height);
void evaluate_bmi(double bmi, int age);
void get_input(double* weight, double* height, int* age);

int main() {
    double weight, height, bmi;
    int age;

    //Eingabe von Gewicht, Groesse und Alter
    get_input(&weight, &height, &age);

    //BMI berechnen
    bmi = calculate_bmi(weight, height);

    // BMI bewerten und Ausgabe
    printf("Ihr BMI betraegt: %.2lf\n", bmi);
    evaluate_bmi(bmi, age);

    return 0;
}

//Funktion zur Berechnung des BMI
double calculate_bmi(double weight, double height) {
    return weight / (height * height);
}

//Funktion zur Bewertung des BMI basierend auf Alter und BMI
void evaluate_bmi(double bmi, int age) {
    if (age < 18) {
        printf("Für Kinder und Jugendliche gelten andere BMI-Kriterien. Bitte einen Arzt konsultieren.\n");
        return;
    }

    if (bmi < 18.5) {
        printf("Sie sind untergewichtig.\n");
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Ihr Gewicht ist normal.\n");
    } else if (bmi >= 25.0 && bmi < 29.9) {
        printf("Sie haben uebergewicht.\n");
    } else if (bmi >= 30.0 && bmi < 34.9) {
        printf("Sie haben Adipositas (Grad 1).\n");
    } else if (bmi >= 35.0 && bmi < 39.9) {
        printf("Sie haben Adipositas (Grad 2).\n");
    } else {
        printf("Sie haben extreme Adipositas (Grad 3).\n");
    }

    if (age >= 65 && bmi >= 25.0 && bmi <= 29.9) {
        printf("Für aeltere Menschen ist ein hoeherer BMI oft vorteilhaft.\n");
    }
}

// Funktion zur Eingabe von Gewicht, Größe und Alter
void get_input(double* weight, double* height, int* age) {
    printf("Geben Sie Ihr Gewicht in Kilogramm ein: ");
    scanf("%lf", weight);

    printf("Geben Sie Ihre Groesse in Metern ein (z.B. 1.75): ");
    scanf("%lf", height);

    printf("Geben Sie Ihr Alter ein: ");
    scanf("%d", age);
}

