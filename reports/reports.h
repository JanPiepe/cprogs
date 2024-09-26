#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define PATH "reports.txt"

typedef enum
{
    READ = 0,
    WRITE = 1,
}Mode;

typedef struct JFP_Line
{
    int lineID;
    char* _eingabe[1024];
    struct JFP_Line* nextLine;
    struct JFP_Line* prevLine;
} jfp_line;

bool doesFileExist(FILE** file); // Checks if file exists
bool openFile(FILE** file, Mode mode); // Opens reports.txt and checks if file exist
void closeFile(FILE** file); // Closes reports.txt
void loadReports(FILE** file, jfp_line* firstElem, jfp_line* lastElem);

char* readConsoleInput(char* input);
char getUserOption(char* input);
