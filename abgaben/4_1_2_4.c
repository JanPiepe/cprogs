/*Variablen und Datentypen 4 --- adressen der Variablen */

#include <stdio.h>

int main(void)
{

char buchstabe = 'a';
int zahl_1 = 5;
float zahl_2 = 3;

printf("\nDie Character-Variable Buchstabe liegt im Arbeitsspeicher an Adresse %x und enthält ein %c", &buchstabe, buchstabe);
printf("\nDie int-Variable Buchstabe liegt im Arbeitsspeicher an Adresse %x und enthält ein %i", &zahl_1, zahl_1);
printf("\nDie float-Variable Buchstabe liegt im Arbeitsspeicher an Adresse %x und enthält ein %.2f", &zahl_2, zahl_2);

/*Erweitern Sie diese Aufgabe auf die Adress-Anzeige der weiteren Variablen*/

return 0;

}