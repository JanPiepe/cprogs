
int add(int zahl1,int zahl2, char op)
{

if (op == '+')
{
    int erg1 =  zahl1 + zahl2;
    return erg1;
}

return 0;
}



int sub(int zahl1,int zahl2)
{
int op;

if (op == '-')
{
int erg2 =  zahl1 - zahl2;
    return erg1;
}

return 0;
}



int mul(int zahl1,int zahl2)
{
int op;

if (op == '*')
{
int erg3 =  zahl1 * zahl2;
    return erg1;

}

return 0;
}



int dev(int zahl1,int zahl2)
{
    int op;

    if (op == '/')
    {

        if (zahl2 != 0)
        {
            int erg4 =  zahl1 / zahl2;
            return erg1;
        }
        else
        {
            printf("durch Null nicht teilbar!");
            return 0;
        }
    }
}


















