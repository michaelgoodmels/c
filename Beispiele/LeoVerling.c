#include <stdio.h>
#include <math.h>

int zahl;

int main(void)
{
    int zahl;
    printf("Eine Zahl von 1-10 nennen: ");
    scanf("%d", &zahl);
    if (zahl == 1) {
        printf("1 ist der Anfang der Zahlen.\n");
    } else if (zahl == 2) {
        printf("2 ist ein schon ein Paar\n");
    } else if (zahl == 3) {
        printf("3 ist schon ein Drittel\n");
    } else if (zahl == 4) {
        printf("4 Personen\n");
    } else if (zahl == 5) {
        printf("5 Finger\n");
    } else if (zahl == 6) {
        printf("die Perfekte Zahl ist 6\n");
    } else if (zahl == 7) {
        printf("7 sieht fast aus wie eine Eins\n");
    } else if (zahl == 8) {
        printf("Umgedreht ist die 8 Unendlich\n");
    } else if (zahl == 9) {
        printf("9 ist die höchste Zahl im dezimal\n");
    } else if (zahl == 10) {
        printf("die grösste Zahl von hier ist 10\n");
    } else {
        printf("falsche Zahl\n");
    }

    return 0;
}