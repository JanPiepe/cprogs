#include <stdio.h>
#include <stdlib.h>

typedef struct JFP_Line
{
    int lineID;
    char* _eingabe[1024];
    struct JFP_Line* nextLine;
} jfp_line;

int main()
{
    int n = 1;
    jfp_line* firstLines;
    jfp_line* lastLines;

    firstLines = ((jfp_line*) malloc(sizeof(jfp_line)));

    char* curLine[1024];
    gets(&curLine);
    *firstLines->_eingabe = *curLine;
    firstLines->lineID = n;

    while(1)
    {
        n++;
        lastLines = ((jfp_line*) malloc(sizeof(jfp_line)));
        gets(&curLine);
        *lastLines->_eingabe = *curLine;
        lastLines->lineID = n;
    }
}