#include<stdio.h>

int main()
{
  long nummer;
  double betrag;
 
  printf("\nBitte geben Sie die Kontonummer ein:\n" );
  scanf( "%8ld", &nummer);   //Feldbreite hier auf 8 begrenzt

  //bei cygwin-Compilern funktioniert es - s. linux manual page für scanf (man scanf)
 
  fflush(stdin); // Den Eingabe-Puffer löschen
 
  printf("\n Bitte den Geldbetrag eingeben:  ");
  scanf( "%lf ", &betrag);

//Hier folgt nun das weitere Programm...

  return 0;
}