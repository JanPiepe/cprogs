#include "4166.h"


bool jfp_c_isOper (jfp_calc* jfp_c, char oper)
{
    if(oper == '+')
    {
        return true;
    }
    if(oper == '-')
    {
        return true;
    }
    if(oper == '*')
    {
        return true;
    }
    if(oper == '/')
    {
        return true;
    }
    return false;
}

void jfp_c_setOper(jfp_calc* jfp_c, char oper)
{

    // Könnte auch via swtich case gelöst werden, copy pasta ist aber schneller xD
    if(oper == '+')
    {
        jfp_c->_oper = oper;
    }
    if(oper == '-')
    {
        jfp_c->_oper = oper;
    }
    if(oper == '*')
    {
        jfp_c->_oper = oper;
    }
    if(oper == '/')
    {
        jfp_c->_oper = oper;
    }
}

void jfp_c_divideEingabe(jfp_calc* jfp_c)
{
    int k = 0;
    int l = 0;
    int j = 0;
    bool firstNum = true;
    char c = 0x0;
    char z1_tmp[100] = {};
    char z2_tmp[100] = {};

    while(1)
    {
        c = jfp_c->_eingabe[k];
        k++;

        if(c == '\n' || c == 0x3 || c == 0x0) // Ende while schleife wenn wir das ende des Text sehen
            break;
        
        if(jfp_c_isOper(jfp_c, c))
        {
            jfp_c_setOper(jfp_c, c);
            firstNum = false;
            continue;
        }

        if(firstNum)
        {
            z1_tmp[l] = c;
            l++;
        }
        else
        {
            z2_tmp[j] = c;
            j++;
        }
    }

    jfp_c->_zahl1 = atof(z1_tmp);
    jfp_c->_zahl2 = atof(z2_tmp);
}