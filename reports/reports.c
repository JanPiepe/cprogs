#include "reports.h"

bool doesFileExist(FILE** file)
{
    if(file == NULL)
    {
        printf("\nNo reports.txt found!\n");
        return false;
    }
    return true;
}

bool openFile(FILE** file, Mode mode)
{
    if(mode == READ)
    {
        *file = fopen(PATH, "r");

        if(doesFileExist(file))
            return true;

        return false;
    }

    if(mode == WRITE)
    {
        *file = fopen(PATH, "w");
        if(doesFileExist(file))
            return true;

        return false;
    }
    return false;
}

void closeFile(FILE** file)
{
    if(doesFileExist(file))
        fclose(*file);
}


void loadReports(FILE** file, jfp_line* firstElem, jfp_line* lastElem)
{
    int i = 1;
    bool isFirst = true;
    char input[1024] = {};
    char* getTest;

    jfp_line* curLine = NULL;
    jfp_line* lastLine = NULL;

    if(openFile(file, READ))
    {
        while(1)
        {
            getTest = fgets(input, sizeof(input), *file);

            if(!getTest)
                break; // getTest is NULL when we reached EOF or Error is encountered

            curLine = ((jfp_line*) malloc(sizeof(jfp_line)));

            curLine->lineID = i;
            i++;
            strcpy((char*)curLine->_eingabe, input);

            if(isFirst)
            {
                firstElem = curLine;
                curLine->prevLine = NULL;
                curLine->nextLine = NULL;
                isFirst = false;
            }else
            {
                curLine->prevLine = lastLine;
                curLine->nextLine = NULL;
            }
            lastLine = curLine;
        }
        closeFile(file);
    }
    lastElem = lastLine;
}

char* readConsoleInput(char *input)
{
    return 0x0;
}

char getUserOption(char *input)
{

}