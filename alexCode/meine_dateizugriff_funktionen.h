#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int erzeugenundfuellen(char eingabe[], FILE *datei, int c){

    datei=fopen(eingabe,"r+");

    if(datei!=NULL){

        while((c=fgetc(datei))!=EOF){

            putchar(c);
        }

        return 0;
    }

    else{

        printf("\n Konnte Datei nicht anlegen. \n");

        return 0;
    }
}

int oeffnenundanhaengen(char eingabe[], FILE *datei, int c){

    datei=fopen(eingabe,"a+");

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

int oeffnenundanzeigen(char eingabe[], FILE *datei, int c){

    int i=0;

    datei=fopen(eingabe,"r");

    if(datei!=NULL){

        while((c=fgetc(datei))!=EOF || i<3){

            putchar(c);

            if((c=fgetc(datei))=='\n'){

                i++;
            }
        }

        return 0;
    }

    else{

        printf("\n Konnte Datei nicht finden bzw. nicht öffnen. \n");

        return 0;
    }
}
