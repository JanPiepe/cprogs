#include "reports.h"
#include "reports.c"

int main ()
{
    FILE* file;

    jfp_line* firstElem = NULL;
    jfp_line* lastElem = NULL;

    char* input[1024] = {};
    __u_int input_n; // from stddef.h, short form of unsigned int
    input_n = 4;

    char option = 0; // we using char as an 8bit int
    bool fileExist;


    // Check if reports.txt exist, temporary opens it.
    fileExist = openFile(&file, READ);
    closeFile(&file);

    if(fileExist)
    {
        // When the file exist we load reports
        loadReports(&file, &firstElem, &lastElem);
        initList(&lastElem);
    }

    printf("Choose an Option: (A)dd, (S)how, (E)xit\n");
    option = getUserOption((char*)input, &input_n);

    execOption(&file, &firstElem, option);
    return 0;
}