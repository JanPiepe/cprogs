#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#ifndef ENUM
#define ENUM
#include"enum.h"
#endif


void getWord(char* word, sbt satzteil_typ){
   

    char data_path[128]={"\0"};
    //get filePath(data_path, satzteil_typ)
    switch(satzteil_typ){
        case SUBJEKT:
            strcpy(data_path, "data/subjekte.txt");
            break;
        case PRAEDIKAT:
            strcpy(data_path, "data/praedikate.txt");
            break;
        case OBJEKT:
            strcpy(data_path, "data/objekte.txt");
            break;
        case ADVERB:
            strcpy(data_path, "data/adverbien.txt");
            break;
    }
    


    FILE* file_ptr;

    //counts words in filepath -1
    int max_index = 0;
    char tmp ='0';

    file_ptr = fopen(data_path,"r");
    while( (tmp = fgetc(file_ptr) ) != EOF){
        if(tmp==';'){
            max_index++;
        }
    }
    fclose(file_ptr);
    

    //picks random number between 0 and max_index
    int n = rand() % max_index;

    //gets word on position n in filepath
    char tmp_str[128]={"\0"};
    char bukstab='0';
    file_ptr = fopen(data_path,"r");
    for(int h=0; h<=n && bukstab!=EOF; h++){
        tmp_str[0]='\0';
        for(int i=0; sizeof(tmp_str); i++){     //caps at reaching tmp_str's end to prevent stack overflow,  CREATES new condition: words cant exeed length of 32 chars!
            bukstab = fgetc(file_ptr);

            if((bukstab==EOF) || (bukstab==';')) tmp_str[i]='\0';
            if((bukstab==EOF) || (bukstab==';')) break;

            tmp_str[i]=bukstab;
        }
    }
    fclose(file_ptr);



    strcpy(word, tmp_str);
}