#include "4166.h"

int main()
{
    struct JFP_Calculator all_Calcs[10];
    int maxCalcs = 9;

    while(1)
    {
        char input[1024] = {};
        char input_tmp = 0x0;
        int i_input = 0;

        printf("Gebe eine rechen aufgabe ein z.B. 25+25.\n");

        while(1)
        {
            input_tmp = getc(stdin);
            
            if(input_tmp == '\n' || input_tmp == 0x0 || input_tmp == 0x3)
            {
                break;
            }

            input[i_input] = input_tmp;
            i_input++;
        }

        jfp_c_setEingabe(&all_Calcs[maxCalcs], input);
        jfp_c_divideEingabe(&all_Calcs[maxCalcs]);

        switch (jfp_c_getOper(&all_Calcs[maxCalcs]))
        {
        case '+':
            jfp_c_addieren(&all_Calcs[maxCalcs]);
            break;
        case '-':
            jfp_c_subtrahieren(&all_Calcs[maxCalcs]);
            break;
        case '*':
            jfp_c_multiplizieren(&all_Calcs[maxCalcs]);
            break;
        case '/':
            jfp_c_dividieren(&all_Calcs[maxCalcs]);
            break;
        }

        printf("Das ergebnis ist: %.2f", jfp_c_getOutput(&all_Calcs[maxCalcs]));

        maxCalcs--;
        if(maxCalcs == 0)
        {
            printf("\nMaximale Kalkulationen erreicht! \n");
            break;
        }
    }
}

#include "jfp_c.c"