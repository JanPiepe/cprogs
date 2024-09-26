#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// TODO: JFP header Datei erstellen
void emptyLine() // Fügt eine leere zeile in die Konsole ein
{
    printf("\n");
}

bool isNum(char ch, bool withSeperators) // Checkt ob der char ein Zahl ist
{
    // 0-9 in hexadecimal
    if(ch >= 0x30 && ch <= 0x39)
        return true;

    if(withSeperators && ch == 0x2E) //erlaube punkte
        return true;

    return false;
}

float toFloat(char ch)
{
    float flotty;
}

int main()
{
    char ch;
    char zahlen[40];
    bool isOK = true;
    int i = 0;

    while(1)
    {
        ch = getc(stdin);
        zahlen[i] = ch; // Ausgabe aufgabe 1
        if (ch == '\n' || i > 99 || !isNum(ch, true))
        {
            if(!isNum(ch, true) && ch != '\n')
            {
                printf("Ein nicht Zahl wurde erkannt: \"%c\"", ch);
                emptyLine();
                isOK = false; // Ausgabe abbruch, nur Fehler meldung wird ausggeben

                break;
            }

            //printf("%i", i)
            break;
        }

        i++;
    }

    if(isOK)
    {
        float flotty = strtof(zahlen, NULL);
        emptyLine();
        printf("Deine Zahl war: %f", flotty);
        emptyLine();
        printf("Ohh Hallo float conversion bug");
        emptyLine();
    }
    return 0;
}
