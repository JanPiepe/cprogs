#include <stdio.h>

int main()
{

   char vertreter [2][1024] = {"Lauber, Otto", "Forsch, Heidi" };

   //Jeder Vertreter hat vier verschiedene Artikel
  //im Sortiment, davon wurden verkauft:

  int artikel_anzahl [2][4] = { {20, 5, 30, 17} , {150, 120, 90, 110} };

  int i, j;

   for(i = 0; i <  2; ++i )
     {
      printf("\n\nVertreter: %s ", vertreter[i]);
      printf("Verkaufte Stückzahlen: ");
      
       for(j = 0; j < 4; ++j)
         {
          printf("\n%8d", artikel_anzahl[i] [j] );
         }
      }
   printf("\n");

   return 0;
}