#include <stdio.h>

int main(void)
{

float i = 5;
float x = 0.f;
printf("\n in der Variable i steht eine %.0f", i);
printf("\n Bitte geben Sie eine Zahl ein.\n");

fflush(stdin);
scanf("%f", &x);

printf("\n in der Variable x steht eine %.2f", x);


printf("\n i + x = %.2f", (i+x));
printf("\n i - x = %.2f", (i-x));
printf("\n i * x = %.2f", (i*x));
printf("\n i / x = %.2f", (i/x));

return 0;
/*Bitte erweitern Sie das zu einem "Taschenrechner" für die vier Grundrechenarten*/
}