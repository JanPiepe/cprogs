#include <stdio.h>

int main ()
{
	char x, x_tmp = 0x0;
	int n = 0;
	int kase = 0;

	printf("Drücke schnell Enter!!!\n");
	printf("Drücke iregendwann danach x und Enter!\n");

	// Wir machen nanana bis der user x drückt
	while(x != 'x')
	{
		x_tmp = (char) getc(stdin);
		if(x_tmp != 'x')
		{
			printf("Nanana");
			n++;
		}
		x = x_tmp;
	}

	// wir machen BATMAN exakt 1x mal, warum do while? Nur in ausnahme fällen sollte do while verwendet
	// werden wenn eine normale while WIRKLICH nicht verwendet werden kann.
	do{
		printf("\nBATMAN");
	}while( 0 == 1 );

	// für jedes Nanana gibt es hiter BATMAN ein !
	for(int i = 0; i <= n; i++)
	{
		printf("!");
	}

	// Wir schauen we schnell jemand war
	if(n > 0 && n < 31)
	{
		printf("\nEs wurde %i mal Nanana gemacht.\n", n);
		kase = 1; // wir setzen den käse für den switch cäse
	}
	else if(n > 30)
	{
		printf("\nDu hast lange gebraucht, es wurde %i mal Nanana gemacht.\n", n);
		kase = 2;
	}
	else if(n == 0)
	{
		printf("\nSchnell finger Archivement freigeschaltet!\n");
		kase = 3;
	}
	else // sollte klappen... wirft aber fehler meldung ???
	{
		printf("\nFEHLER!! Wie bist du hier her gekommen??!?!");
	}

	// Je nach schnellichkeit gibt es verschiedene Strings, der wurst käs wäre default:
	switch (kase)
	{
	case 1:
		printf("\n Du warst normal schnell");
		break;
	case 2:
		printf("\n Versuch x Schneller zu drücken");
		break;
	case 3:
		printf("\n Wow du bist gut");
		break;
	default:
		printf("\n FEHLER!!! Wut?");
		break;
	}
	printf("\n"); // warum nicht? sieht halt schön aus
}
