#include "reader.h"

/*引导界面显示*/
void LeadInterface(void)
{
	system("cls");
	printf("\n\n\n\t\t\t\t\t_________________________________\n");
	printf("\t\t\t\t\t|      请输入所需操作序号       |\n");
	printf("\t\t\t\t\t|  1.采编入库                   |\n");
	printf("\t\t\t\t\t|  2.删除书籍                   |\n");
	printf("\t\t\t\t\t|  3.借阅书籍                   |\n");
	printf("\t\t\t\t\t|  4.返还书籍                   |\n");
	printf("\t\t\t\t\t|  5.查找书籍                   |\n");
	printf("\t\t\t\t\t|  6.修改书籍信息               |\n");
	printf("\t\t\t\t\t|  0.退出                       |\n");
	printf("\t\t\t\t\t|_______________________________|\n");
}

LReaderList CreateReaderList(void)
{
	LReaderList LR;
	extern LReader *Rhead, *Rtail;
	LR = (LReader *)malloc(sizeof(LReader));
	Rhead = LR;
	Rtail = LR;
	Rhead->next = NULL;
	Rhead->pre = NULL; 
	return LR;
}

void ReaderOperation()
{
	int option; 
		
}

void AddReaders(void)
{
	extern LReader *Rhead, *Rtail;
	LReader *reader;
	 
}
