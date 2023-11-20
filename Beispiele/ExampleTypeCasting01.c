/*
Autor: Michael Good
Beispiel: Type Casting 01
Datum: 19.11.23
Version: 0.1
*/

//Präprozessor initialisieren
#include <stdio.h>
#include <math.h>

//globale Variablendekaration
int x = 0;
int y = 0;
int z = 0;

//Funktionsprototyping
void TypeCasting01();
void TypeCasting02();
void TypeCasting03();

//Hauptprogramm
void main(){

TypeCasting01();
TypeCasting02();
TypeCasting03();

return 0;
}

//Funktionsdeklarationen
//Type Casting 01
void TypeCasting01(){

int wert_int;
double wert_double = 10.0;

wert_int = wert_double; /* wert_int = 10 */*/

printf("wert_int = %d, &wert_int")

return 0;
}

//Type Casting 02
void TypeCasting02(){

float ergebnis;
int x = 10;
int y = 3;

ergebnis = x/y;
pintf("Ergebnis : %f\n", ergebnis); /*3.0000*/

return 0;
}

//Type Casting 03
void TypeCasting03(){

float ergebnis;
int x = 10;
int y = 3;

ergebnis = (float) x / y;
pintf("Ergebnis : %f\n", ergebnis); /*3.0000*/

return 0;
}
