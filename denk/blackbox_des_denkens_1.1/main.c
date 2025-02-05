#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"myfunc.h"
#ifndef ENUM
#define ENUM
#include"enum.h"
#endif


typedef struct{
    char subjekt[32];
    char praedikat[128];
    char adverb[128];
    char objekt[128];
    char cap;
}sentence;

void printSentence(sentence satz){
    printf("%s %s %s %s%c\n", satz.subjekt, satz.praedikat, satz.adverb, satz.objekt, satz.cap);
}

void getSentence(sentence* satz){
    srand(time(NULL));

    getWord(satz->subjekt, SUBJEKT);
    getWord(satz->praedikat, PRAEDIKAT);
    getWord(satz->adverb, ADVERB);
    getWord(satz->objekt, OBJEKT);
    satz->cap ='.';
}

int main(){
    
    sentence satz={.subjekt="\0", .praedikat="\0", .adverb="\0", .objekt="\0", .cap='\0'};
    getSentence(&satz);
    printSentence(satz);

    return 0;
}