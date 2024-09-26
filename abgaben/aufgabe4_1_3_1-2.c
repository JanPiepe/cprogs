#include <stdio.h>
#include <stdbool.h>

// TODO: JFP header Datei erstellen
void emptyLine() // Fügt eine leere zeile in die Konsole ein
{
	printf("\n");
}

bool isChar(char ch, bool withSpace) // Checkt ob der char ein Buchstabe ist A-Z u. a-z
{
	// A-Z u. a-z in hexadecimal
	if((ch >= 0x41 && ch <= 0x5A) || (ch >= 0x61 && ch <= 0x7A))
	       return true;

	if(withSpace && ch == 0x20)
		return true;

	return false;
}

char toLowCase(char ch) // Formatiert alle Großbuchstaben in Kleinbuchstaben
{
	// Nur A-Z werden geändert
	if(ch >= 0x41 && ch <= 0x5A)
	{
		ch = ch + 0x20; // ändern des Hexadecimal wert um HEX 20
		return ch;
	}
	return ch;
}

int main()
{
	char chars[100];
	char charsLow[100];
	char zahlen[40];
	char ch;

	bool isOK = true;
	int i = 0; // itorator für den getc(stdin) stream

	while(1)
	{
		ch = getc(stdin);
		chars[i] = ch; // Ausgabe aufgabe 1
		charsLow[i] = toLowCase(ch); // Ausgabe aufgabe 2
		if (ch == '\n' || i > 99 || !isChar(ch, true))
		{
			if(!isChar(ch, true) && ch != '\n')
			{
				printf("Ein nicht Buchstabe wurde erkannt: \"%c\"", ch);
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
		emptyLine();
		printf("Deine Buchstaben waren: %s", chars);
		emptyLine();
		printf("Deine Buchstaben in klein sind: %s", charsLow);
	}
	
	return 0;
}
