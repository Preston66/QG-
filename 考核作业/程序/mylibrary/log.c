#include "log.h"

extern char *wday[]; 
extern const char* LogFileName;

void PrintfTmie(void)
{
	time_t timep;
	struct tm *mytime;
	
	time(&timep);
	mytime = gmtime(&timep);
	printf("%d/%d/%d  ", (1900+mytime->tm_year), (1+mytime->tm_mon), mytime->tm_mday);
	printf("%s  %d:%d:%d\n", wday[mytime->tm_wday], mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
}

void OperationLog(int option)
{
	FILE *fp;
	
		time_t timep;
	struct tm *mytime;
	
	time(&timep);
	mytime = gmtime(&timep);
	
	if((fp=fopen(LogFileName, "w"))==NULL)
	{
		perror("Error~ \n");
	}
	else
	{
		switch(option)
		{
			case 1:
				fprintf(fp, "你进行了添加书籍操作\t");
				break;
			case 2:
				fprintf(fp, "你进行了删除书籍操作\t");
				break;
			case 3:
				fprintf(fp, "你进行了借书操作\t"); 
				break;
			case 4:
				fprintf(fp, "你进行了还书操作\t");
				break;
			case 5:
				fprintf(fp, "你进行了查书操作\t"); 
				break;
			case 6:
				fprintf(fp, "你进行了修改书籍信息操作\t");
				break; 
		}
		fprintf(fp, "%d/%d/%d  ", (1900+mytime->tm_year), (1+mytime->tm_mon), mytime->tm_mday);
		fprintf(fp, "%s  %d:%d:%d\n", wday[mytime->tm_wday], mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	}
	fclose(fp);
}
