#include <stdio.h>

int main()
{
    //Aufgabe 2

    int zahl[6] = {0, 1, 17};
    for(int i = 0; sizeof(zahl) >= (sizeof(int)*i); i++) // sizeof(zahl) gibt uns die lange des arrays in bytes.
    // sizeof(int) gibt uns die anzahl an bytes von int. 
    {
        printf("Das Vektorelement %i hat diesen wert: %i \n", i, zahl[i]);
    }

    // Aufgabe 3

    int zahl2[] = {3,9,17};
    
    printf("Die Vektoradresse von zahl[] lautet: %x \n",  zahl2);
    printf("Die Vektoradresse von zahl[] lautet: %x \n",  &zahl2[0]);

    printf("Die Vektoradresse von zahl[] lautet: %x \n",  zahl2+1);
    printf("Die Vektoradresse von zahl[] lautet: %x \n",  &zahl2[1]);

    printf("Die Vektoradresse von zahl[] lautet: %x \n",  zahl2+2);
    printf("Die Vektoradresse von zahl[] lautet: %x \n",  &zahl2[2]);

    // Aufgabe 4
    char s[] = "münchen";

    printf("Das Wort lautet: %s: \n", s/*nein danke[]*/);


    for(int i = 0; sizeof(s) >= (sizeof(char)*i); i++) // sizeof(s) gibt uns die lange des arrays in bytes.
    // sizeof(s) gibt uns die anzahl an bytes von char. 
    {
        printf("Das Vektorelement %i hat diesen wert: %c in HEX: %x \n", i, s[i], s[i]);
    }

    printf("\n %x \n",'\0');
    printf("\n %x \n",EOF);
}