#include <stdio.h>
#include <string.h>

typedef struct JFP_Line
{
	int lineID;
	char* _eingabe[1024];
} jfp_line;

int main(int argvc, char *argv[])
{
    char path[1024] = {};
    char output[1024] = {};
    jfp_line lines[1024] = {};

    if(argvc == 1)
    {
        printf("Bitte gebe einen Argument an \n");
        return 0;
    }
    if(argvc > 2)
    {
        printf("Zuviele argumente \n");
    }

/*
    printf("%i \n", argvc);
    for(int i = 1; i <= argvc-1; i++)
    {
        printf("%s \n", argv[i]);
    }
    printf("%s \n", argv[0]);

    printf("%s\n", path);
*/
    
    
    strcpy(path, argv[1]);
    FILE *file = fopen(path,"r");
    if(file == NULL)
    {
        printf("\nFile not found\n");
        return 1;
    }

    int i = 0;
    while(fgets(output, 1022, file))
    {
        strcpy(lines[i]._eingabe, output);
        i++;
    }
    fclose(file);

    int ii = 0;
    while(lines[ii]._eingabe[0] != 0x0)
    {
        printf("%s",lines[ii]._eingabe);
        ii++;
    }
    
}


