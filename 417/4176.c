#include <stdio.h>

void strcat2(char s1[], char *s2)
{
    int i = 0;
    while(s1[i] != '\0')
    {
        i++;
    }
    int maxA = sizeof(*s1) / sizeof(char) ;
    while(*s2 != '\0')
    {
        s1[i] = *s2;
        i++;
        s2++;
    }
}

int main()
{
    char s1[100] = {"das "};
    char* s2 = "boot";

    strcat2(&s1, s2);

    int maxA = sizeof(s1) / sizeof(char) ;
    printf("\n %s", s1);
}