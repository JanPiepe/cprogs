#include <stdio.h>
#include <stdlib.h>

void emptyLine()
{
	printf("\n");
}

int main()
{
	/*for (int i = 0; i < 250; i++)
	{
	   printf ("Characters: %i %c \n", i, i);
   	}
	

	printf(">%-10s<-->%5.4s<","Tomate","Tomate");
	*/

	int day, month, year;
	printf("Gebe dein Geburtstag ein. \n");

	printf("Day:\n");
	scanf("%i", &day);

	fflush(stdin);

	printf("Month:\n");
	scanf("%i", &month);

	fflush(stdin);

	printf("Year:\n");
	scanf("%i", &year);

	srand(day + month + year);
	emptyLine();
	printf("Dein Geburtstag %i.%i.%i", day, month, year);
	emptyLine();
	printf("Deine Gluckszahl ist: %i", rand());


	return 0;
}
