typedef struct JFP_Line
{
    int lineID;
    char* _eingabe[1024];
    struct JFP_Line* nextLine;
} jfp_line;