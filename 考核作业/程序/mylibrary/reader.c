#include "reader.h"

/*����������ʾ*/
void LeadInterface(void)
{
	system("cls");
	printf("\n\n\n\t\t\t\t\t_________________________________\n");
	printf("\t\t\t\t\t|      ����������������       |\n");
	printf("\t\t\t\t\t|  1.�ɱ����                   |\n");
	printf("\t\t\t\t\t|  2.ɾ���鼮                   |\n");
	printf("\t\t\t\t\t|  3.�����鼮                   |\n");
	printf("\t\t\t\t\t|  4.�����鼮                   |\n");
	printf("\t\t\t\t\t|  5.�����鼮                   |\n");
	printf("\t\t\t\t\t|  6.�޸��鼮��Ϣ               |\n");
	printf("\t\t\t\t\t|  0.�˳�                       |\n");
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
