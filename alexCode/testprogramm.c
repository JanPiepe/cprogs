#include"meine_dateizugriff_funktionen.h"
#include<stdio.h>
#include<string.h>

int main(){

    int c = 0;
    char auswahl = 0x0;
    char eingabe[256] = {};
    char textfile[256] = {};
    FILE *datei = NULL;

    printf("\n Geben Sie bitte den Namen der Textdatei ein.\n");
    fgets(eingabe, 256, stdin);

        for(int i=0; (eingabe[i]!='\n') ;i++){

        printf("\n Test: Textfile: %c \n", eingabe[i]);

        textfile[i]=eingabe[i];
    }

    printf("\n Was möchten Sie mit der Datei machen? ('r' um eine neue Datei zu erstellen/ 'a' um eine existierende Datei zu öffnen) \n");

    auswahl=getc(stdin);
    getc(stdin);
    //scanf("%c", auswahl);

    if(auswahl=='r'){

        erzeugenundfuellen(textfile, &datei, c);
    }

    else if(auswahl=='a'){

        oeffnenundanhaengen(textfile, &datei, c);
    }

    else if(auswahl=='z'){

        oeffnenundanzeigen(textfile, &datei, c);
    }
}
