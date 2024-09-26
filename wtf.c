#include<stdio.h>
#include<time.h>
FILE* fptr;

int main()
	{
	int tmp;
	char strDat[13];//={'h','i','.','t','x','t'};

	time_t tstamp;
	time(&tstamp);
	struct tm *infotime;
	infotime = localtime(&tstamp);
	
	strftime(strDat,10,"%x",infotime);
	strDat[0]= 'a';
	strDat[1]='t';
	strDat[2]='x';
	strDat[3]='t';
	strDat[4]= 'a';
	strDat[5]='t';
	strDat[6]='x';
	strDat[7]='t';
	strDat[8]= '.';
	strDat[9]='t';
	strDat[10]='x';
	strDat[11]='t';
	strDat[12]= 0x0;
	printf("--%s--\n",strDat);

	fptr = fopen(strDat,"w");
    if(fptr == NULL)
    {
        printf("\nFile not found\n");
        return 1;
    }
	fclose(fptr);
	for (int i=0; i<20; i++)
		printf("%x ",strDat[i]);
	printf("\n");
	
	return 0;
	}
