#include "reports.h"
#include "reports.c"

int main ()
{
    FILE* file;
    jfp_line* firstElem;
    jfp_line* lastElem;
    jfp_line* tmpElem;
    bool fileExist;
    char* input[1024];

    // Check if reports.txt exist, temporary opens it.
    fileExist = openFile(&file, READ);
    closeFile(&file);

    if(fileExist)
    {
        // When the file exist we load reports
        loadReports(&file, firstElem, lastElem);
    }
    fgets(input, sizeof(char[1024]), stdin);
    return 0;
}