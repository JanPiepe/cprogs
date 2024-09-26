#include<stdio.h>

struct mitarbeiter      //      Fehlende 2 Bytes???
{
    int lfdNr;          //      2  Bytes  w/ padding 4  Bytes
    float monatGrundGehalt;//   4  Bytes  w/ padding 4  Bytes
    char nachName[30]; //       30 Bytes  w/ padding 30 Bytes
    char vorName[30];  //       30 Bytes  w/ padding 30 Bytes
    char abteilung [30];//      30 Bytes  w/ padding 30 Bytes
};

int main(void)
{
    struct mitarbeiter hansen, meyer;

    //Belegen Sie nun die Struktur-Variable bzw. den Datensatz "hansen":

    hansen.lfdNr = 1;

    strcpy(hansen.nachName, "Hansen");

    strcpy(hansen.vorName, "Hans");

    strcpy(hansen.abteilung, "Buchhaltung");

    hansen.monatGrundGehalt = 3472.64;

    printf("%s %s von der %s verdient %2f Lira.\n", hansen.nachName, hansen.vorName, hansen.abteilung, hansen.monatGrundGehalt);
    int bytes = sizeof(struct mitarbeiter);
    printf("Insgesamter speicher bedarf beträrgt %i bytes", bytes);

    // Wenn padding mit eingerechnet vermissen wir noch 2 bytes die irgendwo noch aus unbekannten gründen sind
}