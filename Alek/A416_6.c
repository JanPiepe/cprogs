
#include<stdio.h>
#include<string.h>
#include"funk6.h"

int main()
{

char endeingabe[4];


do
{
int zahl1;
int zahl2;
char op; 

printf("Hallo das ist ein Taschenrechner\n");

printf("geben sie bitte ihr erste Zahl \n");
scanf("%i",  &zahl1);

printf(" geben sie bitte ihr zweite Zahl\n");
scanf("%i",  &zahl2);

printf("Geben Sie Bitte die Operat ein: \n");
scanf(" %c", &op);

int aerg = add(zahl1,zahl2,op);
int serg = sub(zahl1,zahl2);
int merg = mul(zahl1,zahl2);
int derg = dev(zahl1,zahl2);

int erg = aerg + serg + merg + derg;


printf("Ihr ergebins ist %i \n", erg );


printf("Wollen Sie nochmal rechnen? Ant worten Sie bitte mit ja oder nein! \n");
scanf("%s", &endeingabe);


}
while
(

strcmp (endeingabe, "ja")==0

);







return 0;
}














