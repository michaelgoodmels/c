/*
Projekt:    Rechner
Autor:      Michael Good
Datum:      05.09.2024
Version:    0.3
Kontakt:    michael.good@outlook.com
*/

#include <stdio.h>

// Definition der Taschenrechner-Klasse (struct)
typedef struct {
    double (*add)(double, double);
    double (*subtract)(double, double);
    double (*multiply)(double, double);
    double (*divide)(double, double);
} Calculator;

// Funktionen für die Operationen
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Fehler: Division durch Null!\n");
        return 0;
    }
}

// Initialisieren des Taschenrechners
Calculator init_calculator() {
    Calculator calc;
    calc.add = add;
    calc.subtract = subtract;
    calc.multiply = multiply;
    calc.divide = divide;
    return calc;
}

// Hauptprogramm
int main() {
    Calculator calc = init_calculator();
    double a, b;
    char operation;

    printf("Geben Sie die erste Zahl ein: ");
    scanf("%lf", &a);

    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%lf", &b);

    printf("Wählen Sie eine Operation (+, -, *, /): ");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
            printf("Ergebnis: %.2lf\n", calc.add(a, b));
        break;
        case '-':
            printf("Ergebnis: %.2lf\n", calc.subtract(a, b));
        break;
        case '*':
            printf("Ergebnis: %.2lf\n", calc.multiply(a, b));
        break;
        case '/':
            printf("Ergebnis: %.2lf\n", calc.divide(a, b));
        break;
        default:
            printf("Ungültige Operation!\n");
    }

    return 0;
}
