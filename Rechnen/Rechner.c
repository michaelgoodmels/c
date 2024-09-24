/*
Projekt:    Rechner
Autor:      Michael Good
Datum:      05.09.2024
Version:    0.1
Kontakt:    michael.good@outlook.com
*/

//Includes
#include <stdio.h>
#include <math.h>

//Typendefinition "Struct"
typedef struct {
    double (*add)(double, double);
    double (*subtract)(double, double);
    double (*multiply)(double, double);
    double (*divide)(double, double);
} Calculator;

//Funktionsprototying
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
Calculator init_calculator(void);

//Hauptprogramm
int main() {

    //globale Variablen
    Calculator calc = init_calculator();
    double a, b;
    char operation;

    //Ausgabe/Eingabeanforderung
    printf("Geben Sie die erste Zahl ein: ");
    scanf("%lf", &a);

    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%lf", &b);

    printf("Wählen Sie eine Operation (+, -, *, /): ");
    scanf(" %c", &operation);

    //Auswahl Operation
    switch (operation) {
        //Addition
        case '+':
            printf("Ergebnis: %.2lf\n", calc.add(a, b));
        break;
        //Subtraktion
        case '-':
            printf("Ergebnis: %.2lf\n", calc.subtract(a, b));
        break;
        //Multiplikation
        case '*':
            printf("Ergebnis: %.2lf\n", calc.multiply(a, b));
        break;
        //Division
        case '/':
            printf("Ergebnis: %.2lf\n", calc.divide(a, b));
        break;
        //ungültig
        default:
            printf("Ungültige Operation!\n");
    }
    return 0;
}

//Funktionsaufrufe
//Struct Datentyp in Struktur
Calculator init_calculator() {
    Calculator calc;
    calc.add = add;
    calc.subtract = subtract;
    calc.multiply = multiply;
    calc.divide = divide;
    return calc;
}
//Addition
double add(double a, double b) {
    return a + b;
}
//Subtraktion
double subtract(double a, double b){
    return a - b;
}
//Multiplikation
double multiply(double a, double b){
    return a * b;
}
//Division
double divide(double a, double b){
    if (b != 0) {
        return a / b;
    } else {
        printf("Fehler: Division durch Null!\n");
        return 0;
    }
}
