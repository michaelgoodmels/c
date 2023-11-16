/* Getraenke Automat Version 0.3 */

printf("Getraenke Automat v0.3\n\n");

// Auswahl der Getraenke
int sorte;
printf("Waehlen sie ihr Getraenk aus:\n");
printf("1) Wasser (0,50 Euro)\n");
printf("2) Limonade (1,00 Euro)\n");
printf("3) Bier (2,00 Euro)\n\n");
printf("Geben sie 1, 2 oder 3 ein: ");
scanf("%d", &sorte);

// lege den zu zahlenden Betrag fest
float preis=0;
switch(sorte) {
    case 1: preis = 0.5; break;
    case 2: preis = 1.0; break;
    case 3: preis = 2.0; break;
}

// Eingabe der Menge
int menge=1;
printf("\nGeben sie die gewuenschte Menge ein: ");
scanf("%d", &menge);

// Bezahlvorgang
printf("\n--- Bezahlvorgang ---\n");
float einwurf;
float zuZahlen = preis * menge;
do {
	printf("\nEs fehlen noch %.2f Euro.", zuZahlen);
	printf("\nBitte werfen sie ein Geldstueck ein: ");
	scanf("%f", &einwurf);

	// eingeworfenen Betrag anrechnen
	zuZahlen -= einwurf;
	
} while(zuZahlen > 0.0);

// Ausgabe der Getraenke
printf("\n--- Getraenkeausgabe ---\n");
int i;
for(i=0; i < menge; i++)  {
	printf("\nFlasche %d von %d wurde ausgegeben.", i+1, menge);
}

printf("\n\nVielen Dank, bitte entnehmen sie ihre Getraenke.\n");