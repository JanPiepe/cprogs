#include <stdio.h>

int main()
{
    float f1 = 1.5f;
    float f2 = 34.43f;
    int i1 = -3;
    unsigned int i2 = 6;
    char c1 = 'c';
    char c2[] = "Hello";

    printf("\nf1 speicherte \"%f\" in der Adresse %x mit der größe von %i bytes", f1, &f1, sizeof(f1));
    printf("\nf2 speicherte \"%f\" in der Adresse %x mit der größe von %i bytes", f2, &f2, sizeof(f2));

    printf("\ni1 speicherte \"%i\" in der Adresse %x mit der größe von %i bytes", i1, &i1, sizeof(i1));
    printf("\ni2 speicherte \"%i\" in der Adresse %x mit der größe von %i bytes", i2, &i2, sizeof(i2));

    printf("\nc1 speicherte \"%c\" in der Adresse %x mit der größe von %i bytes", c1, &c1, sizeof(c1));
    printf("\nc2 speicherte \"%s\" in der Adresse %x mit der größe von %i bytes", c2, &c2, sizeof(c2));
    return 0;
}