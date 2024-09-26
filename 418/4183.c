#include<stdio.h>
#include<string.h> // für strcpy
#include<stdlib.h> // für atoi, atof

struct mitarbeiter
{
    int lfdNr;
    char nachName[30];
    char vorName[30];
    char abteilung[30];
    float monatGrundGehalt;
};

//Funktion zum Auslesen eines Datensatzes:

void getData(struct mitarbeiter *p)
{
    printf("\n Laufende Mitarbeiternummer: %i ", p->lfdNr );
    printf("\n Nachname: %s " , p->nachName);
    printf("\n Vorhname: %s " , p->vorName);
    printf("\n Abteilung: %s " , p->abteilung);
    printf("\n Gehalt: %.2f ", p->monatGrundGehalt );
}

//Funktion zum Eingeben von Daten in einen Datensatz:

void setData(struct mitarbeiter *p)
{
    char number[15];
    char salary[10];

    printf("\nBitte geben Sie die lfdNr für den neuen Datensatz ein: ", p);
    fgets(number, 6, stdin);
    p->lfdNr = atoi(number);

    printf("\nBitte geben Sie den korrekten Nachnamen des neuen Mitarbeiters ein: ");
    fgets(p->nachName, 30, stdin);
    printf("\nBitte geben Sie den korrekten Vornamen des neuen Mitarbeiters ein: ");
    fgets(p->vorName, 30, stdin);
    printf("\nBitte geben Sie den korrekte Abteilung des neuen Mitarbeiters ein: ");
    fgets(p->abteilung, 30, stdin);

    printf("\nBitte geben Sie die Gehalt für den neuen Datensatz ein: ", p);
    fgets(number, 9, stdin);
    p->monatGrundGehalt = atof(number);
}    

int main()
{
    struct mitarbeiter unsereMitarbeiter[3] = {};
    static size_t n = sizeof(unsereMitarbeiter) / sizeof(unsereMitarbeiter[0]);
    
    for(int i = 0; i < n; i++)
    {
        setData(&unsereMitarbeiter[i]);
        getData(&unsereMitarbeiter[i]);
    }
}