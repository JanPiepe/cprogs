#include <stdio.h>

int main(void){

float zahl_1, zahl_2, ergebnis;

zahl_1 = 5;
zahl_2 = 3;

ergebnis = zahl_1 / zahl_2;

printf("\n Der Quotient aus dem Divisor %.4f und dem Dividenden %.3f beträgt %.2f \n", zahl_1, zahl_2, ergebnis);

/*Aufgabe: geben Sie das Endergebnis mit 2 gerundeten Nachkommastellen an.*/

return 0;

}