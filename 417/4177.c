#include <stdio.h>

// Eigene Version der Standard-Funktion strstr(): Hier der Prototyp dazu:
static char *strstr(char *str, char *muster);

//Globale Variablendeklaration (in C pfui, in OOP wie c++ oder java aber okay): Das Suchmuster
char line[500], muster[] = "ei";

int main()
{
 int linenr = 0;
 
//solange noch eine Zeile da ist:
while (fgets(line, 500, stdin) != NULL)
 {
   ++linenr;
   if (strstr(line, muster) != NULL) //Falls Muster gefunden
     {
      printf("%3d: %s", linenr, line ); //Zeilennummer und Zeile ausgeben
     }
  return 0;
  }
}

static char *strstr(char *s1, char *s2)
  {
    //Zuerst im Strin s1 den Strin s2 suchen:
    int len = strlen(s2);
   
   for(; *s1 != '\0'; ++s1)
     {
      if(strncmp(s1, s2, len) == 0) // s2 gefunden?
        {
          return s1;                          // Ja: Zeiger auf diese Stelle zurückgeben
        }
     }
 return NULL;                             //NEIN: NULL zurückgeben
  }