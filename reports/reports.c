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


void loadReports(FILE** file, jfp_line** firstElem, jfp_line** lastElem)
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

            // Replacing \n with NULL
            char* n = strchr(input, '\n');
            if(n != NULL)
                *n = 0x0;

            curLine = ((jfp_line*) malloc(sizeof(jfp_line)));

            curLine->lineID = i;
            i++;
            strcpy((char*)curLine->_eingabe, input);

            if(isFirst)
            {
                *firstElem = curLine;
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
    *lastElem = lastLine;
}

void initList(jfp_line** lastElem)
{
    jfp_line* curElem = *lastElem;
    jfp_line* prevElem = NULL;

    while(1)
    {
        prevElem = curElem->prevLine;
        prevElem->nextLine = curElem;

        if(prevElem->prevLine == NULL)
            break;

        curElem = prevElem;
    }
}

void readConsoleInput(char* input, __u_int* input_n, bool allLowerCase)
{
    char c;
    __u_int i = 0;
    bool end = false;

    while(1)
    {
        i++;

        if (allLowerCase)
        {
            c = tolower(getc(stdin));
        }else
        {
            c = getc(stdin);
        }

        if(i == 1024)
        {
            printf("\nMaximum string lenght of 1023 reached!\nPossible loss of Data!\n");
            c = 0x0;
            end = true;
        }

        if(c == '\n')
        {
            // When we reched the end of Input we replace the LF(Line Feed) with a NULL
            // And end the while Loop
            c = 0x0;
            end = true;
        }

        input[i-1] = c;

        if(end)
            break;

    }

    *input_n = i;
}

char getUserOption()
{
    char option = 0x0;

    char* input[1024] = {};
    __u_int input_n; // from stddef.h, short form of unsigned int

    readConsoleInput((char*)input, &input_n, true);
    puts(""); // Adding an empty line for visual clearity

    if(input_n == 2) // input_n also includes NULL as string end
    {
        if(input[0] == (char*)'s')
        {
            option = 1;
            return option;
        }
        if(input[0] == (char*)'a')
        {
            option = 2;
            return option;
        }
        if(input[0] == (char*)'e')
        {
            option = 3;
            return option;
        }
    }else
    {
        if(strcmp((char*)input, "show") == 0)
        {
            option = 1;
            return option;
        }
        if(strcmp((char*)input, "add") == 0)
        {
            option = 2;
            return option;
        }
        if(strcmp((char*)input, "exit") == 0)
        {
            option = 3;
            return option;
        }
    }
    return option;
}

void execOption(FILE** file, jfp_line** firstElem, jfp_line** lastElem, char option)
{
    switch (option)
    {
    case 1:
        showAllReports(firstElem);
        break;
    case 2:
        addReport(file, lastElem);
        break;
    case 3:
        saveReports(file, firstElem);
        break;

    default:
        printf("\nOption was not Recognized\n");
        break;
    }
}

void showAllReports(jfp_line** firstElem)
{
    jfp_line* curLine = *firstElem;
    jfp_line* nextLine;

    while(1)
    {
        puts((char*)curLine->_eingabe);
        nextLine = curLine->nextLine;
        if(nextLine == NULL)
        {
            puts("");
            break;
        }else
        {
            curLine = nextLine;
        }
    }
}

void addReport(FILE** file, jfp_line** endElem)
{
    jfp_line* lastLine = *endElem;
    jfp_line* newLastLine;
    char input[1024] = {};


    readConsoleInput(&input, NULL, false);

    newLastLine = ((jfp_line*) malloc(sizeof(jfp_line)));
    strcpy(newLastLine->_eingabe, input);
    newLastLine->prevLine = lastLine;
    newLastLine->nextLine = NULL;
    newLastLine->lineID = lastLine->lineID + 1;

    lastLine->nextLine = newLastLine;
    lastLine = newLastLine;
}

void saveReports(FILE** file, jfp_line** firstElem)
{
}
