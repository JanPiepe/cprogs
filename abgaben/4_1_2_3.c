/*Variablen und Datentypen 3 --- Variablengroessen*/

#include <stdio.h>

int main(void)
{

char buchstabe = 'a';
int zahl_1 = 5;
float zahl_2 = 3;


printf("\n Eine Character-Variable belegt %i Byte im Arbeitsspeicher", sizeof(buchstabe));
printf("\n Eine IntVariable belegt %i Byte im Arbeitsspeicher", sizeof(zahl_1));
printf("\n Eine FloatyFloat-Variable belegt %i Byte im Arbeitsspeicher", sizeof(zahl_2));

/*Erweitern Sie diese Aufgabe auf die Messung der Groesse von integer- und float-Variablen*/

return 0;

}