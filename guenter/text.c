#include <stdio.h> // standart Input Output. header | getc() printf() definition "stdin"
#include <stdlib.h>

int main ()
{
    float n1, n2 = 0;
    float output = 0.f;
    char oper = 'd';
    char s[100] = {0x0}; // defined behavour
    for(int i = 0; i < 100; i++) // solange i kleiner oder gleich 99 ist, machen wir das zeug unten
    {
        s[i] = getc(stdin);
        printf("%x : %c \n", s[i], s[i]);
        if(s[i] == '\n') // wenn, wir ENTER sehen dann
        {
            break; // bricht die for-schleife ab
        }
    }
    if(s[3] == 0xA)
    {
        n1 = atof(&s[0]);
        n2 = atof(&s[2]);
        oper = s[1];

        if(oper == 0x2B) // +
        {
            output = n1 + n2;
        }
        if(oper == 0x2D) // -
        {
            output = n1 - n2;
        }
        if(oper == 0x2A) // *
        {
            output = n1 * n2;
        }
        if(oper == 0x2F) // /
        {
            output = n1 / n2;
        }

        // switch (oper)
        // {
        //     case '+':
        //         printf("+++");
        //         break;
        //     case '-':
        //         printf("+----");
        //         break;
        //     case '*':
        //         printf("+****");
        //         break;
        //     case '/':
        //         printf("/////");
        //         break;
        //     default:
        //         // code block
        // }

    }

    printf("%.2f\n", output);

    return 0; // defined behaviour
}