#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){

    int c;

    char textfile[256] = {};

    char eingabe[256] = {};

    FILE *datei;

    printf("\n Geben Sie bitte den Namen der Textdatei ein.\n");

    fgets(eingabe, 256, stdin);

    printf("\n Folgende Datei wird geöffnet: %s \n", eingabe);

    for(int i=0; (eingabe[i]!='\n') ;i++){

        printf("\n Test: Textfile: %c \n", eingabe[i]);

        textfile[i]=eingabe[i];

        printf("\n Test: Textfile: %c \n", textfile[i]);
    }

    datei=fopen(textfile,"r");

    if(datei!=NULL){

        while((c=fgetc(datei))!=EOF){

            putchar(c);
        }

        return 0;
    }

    else{

        printf("\n Konnte Datei nicht finden bzw. nicht öffnen. \n");

        return 0;
    }
}