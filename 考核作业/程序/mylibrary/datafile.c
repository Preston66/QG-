#include "datafile.h"


extern const char* filename;

/*�������*/
LBookList CreateLibrary(void)
{
	LBookList L;
	extern LBook *head, *tail;
	L = (LBook *)malloc(sizeof(LBook));
	head = L;
	tail = L;
	head->Booknumber = 0;
	head->next = NULL;
	head->pre = NULL; 
	return L;
}

/*�ɱ���� */
Status Warehousing(void)
{
	extern LBook *head, *tail;
	int option, num;
	LBook *book;
	book = (LBook *)malloc(sizeof(LBook));
	getchar();
	if(book == NULL)
	{
		printf("\t\t\t\t\tû�д洢�ռ���\n");
		return ERROR;
	}
	
	/*��д�鼮��Ϣ*/
	printf("\t\t\t\t\t�뿪ʼ����鼮��Ϣ\n"); 
	printf("\t\t\t\t\t����������\n\t\t\t\t\t");
	gets(book->Bookname);

	printf("\t\t\t\t\t����������\n\t\t\t\t\t");
	gets(book->Author);


	printf("\t\t\t\t\t�������ܿ����\n\t\t\t\t\t");
	scanf("%d",&book->Totalstock); 
	
	printf("\t\t\t\t\t�������ִ���\n\t\t\t\t\t");
	scanf("%d",&book->Existingstock);
	if(book->Existingstock > book->Totalstock)
	{
		printf("\t\t\t\t\t���ִ������������\n");
		printf("\t\t\t\t\t�����������ִ���\n\t\t\t\t\t");
		scanf("%d",&book->Existingstock);
	}	
	book->next = NULL;
	
	printf("\t\t\t\t\t������Ҫϵͳ�Զ���ţ��������Լ���š����Ϊ8λ\n");
	printf("\t\t\t\t\t����1��ϵͳ�Զ���ţ�2�����Լ����\n\t\t\t\t\t");
	scanf("%d",&option);
	if(option == 1)
	{
		book->Booknumber = tail->Booknumber + 1;
		printf("\t\t\t\t\tϵͳ���Ϊ\n\t\t\t\t\t");
		printf("%08d\n",book->Booknumber);		
	} 
	else
	{
		printf("\t\t\t\t\t��������\n\t\t\t\t\t");
		scanf("%d",&book->Booknumber);
	}
	
	tail->next = book;
	book->pre = tail;
	tail = book;
	
	SaveBooks();//�������� 
	return SUCCESS;	 
}

/*ɾ���鼮*/
Status DeleteBook(void) //�������� 
{
	LBook *del = NULL;
	printf("\t\t\t\t\t����Ҫɾ���ı���\n");
	del = Choose();//������Ҫɾ�����鼮 
	printf("\t\t\t\t\t��ɹ���ɾ�����¸��鼮\n"); 
	printf("\t\t\t\t|  ���  |\t����\t|\t����\t|  �ִ�  |  ���  |\n");
	printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", del->Booknumber, del->Bookname, del->Author, del->Existingstock, del->Totalstock);
	if(del->next != NULL)
	{
		del->pre->next = del->next;
		del->next->pre = del->pre;
		free(del);		
	}
	return SUCCESS; 
} 

/*��������*/ 
void SaveBooks()
{
	FILE *fp;
	extern LBook *head, *tail;
	LBook *pos = head->next;
	if((fp=fopen(filename,"w"))==NULL) 
	{
		perror("\t\t\t\t\tError! \n");
	}
	while(pos != NULL) 
	{
		fprintf(fp, "%8d\t%8s\t%8s%8d\t%8d\n", pos->Booknumber, pos->Bookname, pos->Author, pos->Existingstock, pos->Totalstock);
		pos = pos->next;
	}
	fclose(fp);
}

/*��ȡ����*/ 
void GetData(void)
{
	extern LBook *head, *tail;
	LBook *pos, *book;
	FILE *fp;
	head = (LBook *)malloc(sizeof(LBook));
	tail = (LBook *)malloc(sizeof(LBook));
	book = (LBook *)malloc(sizeof(LBook));
	tail = head;
	tail->next = NULL;
	
	if((fp=fopen(filename,"r"))==NULL) 
	{
		perror("\t\t\t\t\tError! \n");
	}
	
	while(fscanf(fp, "%d %s %s %d %d", &book->Booknumber, book->Bookname, book->Author, &book->Existingstock, &book->Totalstock) != EOF)
	{
		book->next = NULL;
		tail->next = book;
		book->pre = pos;
		tail = book;
		book = (LBook *)malloc(sizeof(LBook)); 
	}
}

Status UserChangeInformation(void)
{
	int option, bottom = 1;
	char Booknumber[10] = {0};
	char Infors[60] = {0};
	LBook *change, *pos, *pos1;
	printf("\t\t\t\t\t����Ҫ�޸��ı��鼮����Ϣ\n");
	change = Choose();
	pos = change->next;
	if (pos == NULL) 
		{
			printf("\t\t\t\t\tû���ҵ����鼮\n");
			return ERROR;
		} 
	else 
	{
		printf("\t\t\t\t\t���\t����\t����\t\t�ִ�\t���\n");
		while(pos)
		{
			printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", pos->Booknumber, pos->Bookname, pos->Author, pos->Existingstock, pos->Totalstock);
			pos = pos->next;
		}
	}
	
	pos = change->next;
	if(pos->next == NULL) 
		printf("\t\t\t\t\t�����޸��鼮��ʲô��Ϣ\n");
	else
	{
		printf("\t\t\t\t\t�����޸��ı��鼮����Ϣ\n"); 
		printf("\t\t\t\t\t�����������޸ĵ��鼮���\n\t\t\t\t\t");
		scanf("%s",&Booknumber);
		
		pos = change->next;
		while(pos != NULL)
		{
			if (IsBook(1, Booknumber, pos) == 0) 
			{
				pos1 = pos;
				printf("find it\n");
						printf("\t\t\t\t\t���\t����\t����\t\t�ִ�\t���\n"); 
						printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", pos->Booknumber, pos->Bookname, pos->Author, pos->Existingstock, pos->Totalstock);			
			}
			pos = pos->next;
		}
		printf("find it1\n");
		printf("\t\t\t\t\t���\t����\t����\t\t�ִ�\t���\n"); 
		printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", pos1->Booknumber, pos1->Bookname, pos1->Author, pos1->Existingstock, pos1->Totalstock);
	}
			
	while(bottom)
	{
		printf("\t\t\t\t\t1:���;2:����;3:����;4:�ִ�;5:���;;\n\t\t\t\t\t");
		scanf("%d",&option);
		printf("\t\t\t\t\t�����������޸ĵ���Ϣ\n\t\t\t\t\t");
		scanf("%s",Infors);
		switch(option)
		{
			case 1:				
				pos1->Booknumber = atoi(Infors);
				break;
			case 2:
//				change->Bookname = (char *)malloc(strlen(Infors)+1);//���¿����¿ռ�
				memset(pos1->Bookname, 0, 60*sizeof(char));//��ʼ��
				strcpy(pos1->Bookname, Infors); 
				break;
			case 3:
				memset(pos1->Bookname, 0, 40*sizeof(char));//��ʼ��
				strcpy(pos1->Bookname, Infors);
				break;
			case 4:
				pos1->Existingstock = atoi(Infors);
				break;
			case 5:
				pos1->Totalstock = atoi(Infors);
				break; 
		}
		printf("\t\t\t\t\t���\t����\t����\t\t�ִ�\t���\n"); 
		printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", pos1->Booknumber, pos1->Bookname, pos1->Author, pos1->Existingstock, pos1->Totalstock);		
		
		printf("\t\t\t\t\t0 �˳�������������\n");
		scanf("%d", &bottom);
		printf("\n"); 		
	}
	SaveBooks();//��������
}


