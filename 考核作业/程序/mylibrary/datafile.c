#include "datafile.h"


extern const char* filename;

/*创建书库*/
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

/*采编入库 */
Status Warehousing(void)
{
	extern LBook *head, *tail;
	int option, num;
	LBook *book;
	book = (LBook *)malloc(sizeof(LBook));
	getchar();
	if(book == NULL)
	{
		printf("\t\t\t\t\t没有存储空间了\n");
		return ERROR;
	}
	
	/*填写书籍信息*/
	printf("\t\t\t\t\t请开始添加书籍信息\n"); 
	printf("\t\t\t\t\t请输入书名\n\t\t\t\t\t");
	gets(book->Bookname);

	printf("\t\t\t\t\t请输入作者\n\t\t\t\t\t");
	gets(book->Author);


	printf("\t\t\t\t\t请输入总库存量\n\t\t\t\t\t");
	scanf("%d",&book->Totalstock); 
	
	printf("\t\t\t\t\t请输入现存量\n\t\t\t\t\t");
	scanf("%d",&book->Existingstock);
	if(book->Existingstock > book->Totalstock)
	{
		printf("\t\t\t\t\t请现存量超过库存量\n");
		printf("\t\t\t\t\t请重新输入现存量\n\t\t\t\t\t");
		scanf("%d",&book->Existingstock);
	}	
	book->next = NULL;
	
	printf("\t\t\t\t\t你是想要系统自动编号，还是你自己编号。编号为8位\n");
	printf("\t\t\t\t\t输入1：系统自动编号；2：你自己编号\n\t\t\t\t\t");
	scanf("%d",&option);
	if(option == 1)
	{
		book->Booknumber = tail->Booknumber + 1;
		printf("\t\t\t\t\t系统编号为\n\t\t\t\t\t");
		printf("%08d\n",book->Booknumber);		
	} 
	else
	{
		printf("\t\t\t\t\t请输入编号\n\t\t\t\t\t");
		scanf("%d",&book->Booknumber);
	}
	
	tail->next = book;
	book->pre = tail;
	tail = book;
	
	SaveBooks();//保存数据 
	return SUCCESS;	 
}

/*删除书籍*/
Status DeleteBook(void) //还需完善 
{
	LBook *del = NULL;
	printf("\t\t\t\t\t你想要删除哪本书\n");
	del = Choose();//查找想要删除的书籍 
	printf("\t\t\t\t\t你成功的删除以下该书籍\n"); 
	printf("\t\t\t\t|  书号  |\t书名\t|\t作者\t|  现存  |  库存  |\n");
	printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", del->Booknumber, del->Bookname, del->Author, del->Existingstock, del->Totalstock);
	if(del->next != NULL)
	{
		del->pre->next = del->next;
		del->next->pre = del->pre;
		free(del);		
	}
	return SUCCESS; 
} 

/*保存数据*/ 
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

/*获取数据*/ 
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
	printf("\t\t\t\t\t你想要修改哪本书籍的信息\n");
	change = Choose();
	pos = change->next;
	if (pos == NULL) 
		{
			printf("\t\t\t\t\t没有找到该书籍\n");
			return ERROR;
		} 
	else 
	{
		printf("\t\t\t\t\t书号\t书名\t作者\t\t现存\t库存\n");
		while(pos)
		{
			printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", pos->Booknumber, pos->Bookname, pos->Author, pos->Existingstock, pos->Totalstock);
			pos = pos->next;
		}
	}
	
	pos = change->next;
	if(pos->next == NULL) 
		printf("\t\t\t\t\t你想修改书籍的什么信息\n");
	else
	{
		printf("\t\t\t\t\t你想修改哪本书籍的信息\n"); 
		printf("\t\t\t\t\t请输入你想修改的书籍书号\n\t\t\t\t\t");
		scanf("%s",&Booknumber);
		
		pos = change->next;
		while(pos != NULL)
		{
			if (IsBook(1, Booknumber, pos) == 0) 
			{
				pos1 = pos;
				printf("find it\n");
						printf("\t\t\t\t\t书号\t书名\t作者\t\t现存\t库存\n"); 
						printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", pos->Booknumber, pos->Bookname, pos->Author, pos->Existingstock, pos->Totalstock);			
			}
			pos = pos->next;
		}
		printf("find it1\n");
		printf("\t\t\t\t\t书号\t书名\t作者\t\t现存\t库存\n"); 
		printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", pos1->Booknumber, pos1->Bookname, pos1->Author, pos1->Existingstock, pos1->Totalstock);
	}
			
	while(bottom)
	{
		printf("\t\t\t\t\t1:书号;2:书名;3:作者;4:现存;5:库存;;\n\t\t\t\t\t");
		scanf("%d",&option);
		printf("\t\t\t\t\t请输入你想修改的信息\n\t\t\t\t\t");
		scanf("%s",Infors);
		switch(option)
		{
			case 1:				
				pos1->Booknumber = atoi(Infors);
				break;
			case 2:
//				change->Bookname = (char *)malloc(strlen(Infors)+1);//重新开辟新空间
				memset(pos1->Bookname, 0, 60*sizeof(char));//初始化
				strcpy(pos1->Bookname, Infors); 
				break;
			case 3:
				memset(pos1->Bookname, 0, 40*sizeof(char));//初始化
				strcpy(pos1->Bookname, Infors);
				break;
			case 4:
				pos1->Existingstock = atoi(Infors);
				break;
			case 5:
				pos1->Totalstock = atoi(Infors);
				break; 
		}
		printf("\t\t\t\t\t书号\t书名\t作者\t\t现存\t库存\n"); 
		printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", pos1->Booknumber, pos1->Bookname, pos1->Author, pos1->Existingstock, pos1->Totalstock);		
		
		printf("\t\t\t\t\t0 退出，其它键继续\n");
		scanf("%d", &bottom);
		printf("\n"); 		
	}
	SaveBooks();//保存数据
}


