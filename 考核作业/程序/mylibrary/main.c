#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "datafile.h"
#include "log.h"
#include "reader.h" 

LBook *head, *tail;
LReader *Rhead, *Rtail; 

const char* RdFileName = "rd.txt";
const char* LogFileName = "log.txt";
const char* filename   = "bk.txt";

char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; 



int main(void)
{
	LBookList L;
	
	int option; 
//	L = CreateLibrary();//创建书库
	GetData();
	printf("\n\n\n\t\t\t\t\t欢迎来到我的图书馆管理系统\n\n");	
	system("pause");
	while(1)
	{
		LeadInterface();
		printf("\n\n\t\t\t\t\t请输入你的选择:");		
		scanf("%d",&option);
		
		switch(option)
		{
			case 0:
				exit(0);
			case 1:
				if(Warehousing() == SUCCESS)
					printf("\t\t\t\t\t添加成功\n");
				else
					printf("\t\t\t\t\t添加失败，请重新操作\n");
				OperationLog(option);
				PrintBooks();
				break;
			
			case 2:
				 DeleteBook();
				 OperationLog(option);
				 break;
				
			case 3:
				BorrowBooks();
				OperationLog(option);
				break;
				
			case 4:
				RetBooks();
				OperationLog(option);
				break;
				
			case 5:
				FindBooks();
				OperationLog(option);
				break;  
				
			case 6:
				UserChangeInformation();
				OperationLog(option);
				break;
			
			default: ; 
		}
	printf("\n\n\t\t\t\t\t");
	system("pause");
	} 
	return 0;
}
