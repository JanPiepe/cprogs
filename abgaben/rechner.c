#include <stdio.h>

int main(void)
{

    char ch;
    char chars[100];
    int i;

	while(1)
	{
        ch = getc(stdin);

		chars[i] = ch; // Ausgabe aufgabe 1

        if (ch == '\n' || i > 99)
		{
			break;
		}

		i++;
    }

return 0;
/*Bitte erweitern Sie das zu einem "Taschenrechner" für die vier Grundrechenarten*/
}