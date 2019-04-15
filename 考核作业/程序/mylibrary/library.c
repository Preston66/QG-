#include "library.h"

void strcutcpy(LBook *book1, LBook *book2)
{
	strcpy(book1->Author, book2->Author);
	strcpy(book1->Bookname, book2->Bookname);
	book1->Booknumber = book2->Booknumber;
	book1->Existingstock = book2->Existingstock;
	book1->Totalstock = book2->Totalstock; 
}

LBookList FindBooks(void) 
{
	int finding = 1;//查找标志 
	int c;
	LBookList Lfind = NULL;
	LBook *Sbook = NULL;
	printf("\t\t\t\t\t你想要找什么书\n");
	while(finding) 
	{
		Lfind = Choose();
		Sbook = Lfind->next;
		if (Sbook == NULL) 
		{
			printf("\t\t\t\t\t没有找到该书籍\n");
		} 
		else 
		{			
			printf("\t\t\t\t\t成功地找到相关书籍\n");
			printf("\t\t\t\t\t书号\t书名\t作者\t\t现存\t库存\n");
			while(Sbook)
			{
				printf("\t\t\t\t\t%08d%8s%8s%8d\t%8d\n", Sbook->Booknumber, Sbook->Bookname, Sbook->Author, Sbook->Existingstock, Sbook->Totalstock);
				Sbook = Sbook->next;
			}
		}
		printf("\t\t\t\t\t0 退出，其它键继续\n");
		scanf("%d", &c);
		if (c == 0) 
		{
			finding = 0;
		}
		printf("\n");
	}
	return Lfind;
}

LBook *Choose(void)//还需完善 
{
	char key[60] = {0};
	int way, booknumber;
//	int Ishead = 1;//表头标记:1:是表头;0:不是表头 
	extern LBook *head, *tail;
	LBook *pos = head, *r, *s;
	LBookList Lfind = NULL;
	Lfind = (LBook *)malloc(sizeof(LBook));//创建新链表，存储找到的相关书籍 
	Lfind->next = NULL;
//	find = (LBook *)malloc(sizeof(LBook));
	r = Lfind;
	printf("\t\t\t\t\t1:书号;2:书名;3:作者\n");
	printf("\t\t\t\t\t你想通过什么方式查找书籍\n\t\t\t\t\t");
	scanf("%d",&way);
	while(way<=0 || way>=4)
	{
		printf("\t\t\t\t\t请重新输入\n");
		scanf("%d",&way);		
	}
	printf("\t\t\t\t\t请输入关键词\n\t\t\t\t\t");
	scanf("%s",key);
	
	while(pos != NULL)
	{
		if (IsBook(way, key, pos) == 0) 
		{
			s = (LBook *)malloc(sizeof(LBook));
			s->next = NULL;
			strcutcpy(s, pos);
			r->next = s;
			s->pre = r;
			r = s;
//			find = pos;			
		}
		pos = pos->next;
	}
//	return find; 
	return Lfind;
} 

int IsBook(int way, char *key, LBook *pos)
{
	int Booknumber;
	switch(way)
	{
		case 1://通过编号查找 
			Booknumber = atoi(key);
			if(Booknumber == pos->Booknumber)
				return 0;
			break;
		case 2://通过书名查找 
			return strcmp(key, pos->Bookname);
			break;
		case 3://通过作者查找 
			return strcmp(key, pos->Author);
			break;
		default :
			return -1; 
	}
} 

LBook *BorrowBooks1()
{
	LBookList Lfind = NULL;
	LBook *bor = NULL;
	Lfind = Choose();//选择书籍
	bor = Lfind->next;
	if(bor->next == NULL)//如果只找到一本 
	{
		if(bor->Totalstock == 0)
		{
			printf("\t\t\t\t\t该书已被清除\n");
			return ERROR;
		}
		else if(bor->Existingstock == 0)
		{
			printf("\t\t\t\t\t该书已被借完\n");
			return ERROR;
		}
		else
		{
//			bor->Existingstock--;
//			printf("\t\t\t\t\t你已经成功借走该书\n");
//			printf("\t\t\t\t|  书号  |\t书名\t|\t作者\t|  现存  |  库存  |\n");
//			printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
//			SaveBooks();//保存数据
			return bor; 
		}		
	}
	else
	{
		printf("\t\t\t\t\t成功地找到相关书籍\n");
		printf("\t\t\t\t\t书号\t书名\t作者\t\t现存\t库存\n");
		
		while(bor)
		{
			printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
			bor = bor->next;
		}
		printf("\t\t\t\t\t你要借哪本书？\n");
		
		bor = NULL;
		bor = Choose();//再次选择书籍
		if(bor->Totalstock == 0)
		{
			printf("\t\t\t\t\t该书已被清除\n");
			return ERROR;
		}
		else if(bor->Existingstock == 0)
		{
			printf("\t\t\t\t\t该书已被借完\n");
			return ERROR;
		}
		else
		{
//			bor->Existingstock--;
//			printf("\t\t\t\t\t你已经成功借走该书\n");
//			printf("\t\t\t\t|  书号  |\t书名\t|\t作者\t|  现存  |  库存  |\n");
//			printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
//			SaveBooks();//保存数据 
			return bor;
		}		
	} 
}

Status BorrowBooks(void)
{
	LBookList Lfind = NULL;
	LBook *bor = NULL;
	Lfind = Choose();//选择书籍
	bor = Lfind->next;
	if(bor->next == NULL)//如果只找到一本 
	{
		if(bor->Totalstock == 0)
		{
			printf("\t\t\t\t\t该书已被清除\n");
			return ERROR;
		}
		else if(bor->Existingstock == 0)
		{
			printf("\t\t\t\t\t该书已被借完\n");
			return ERROR;
		}
		else
		{
			bor->Existingstock--;
			printf("\t\t\t\t\t你已经成功借走该书\n");
			printf("\t\t\t\t|  书号  |\t书名\t|\t作者\t|  现存  |  库存  |\n");
			printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
			SaveBooks();//保存数据 
		}		
	}
	else
	{
		printf("\t\t\t\t\t成功地找到相关书籍\n");
		printf("\t\t\t\t\t书号\t书名\t作者\t\t现存\t库存\n");
		
		while(bor)
		{
			printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
			bor = bor->next;
		}
		printf("\t\t\t\t\t你要借哪本书？\n");
		
		bor = NULL;
		bor = Choose();//再次选择书籍
		if(bor->Totalstock == 0)
		{
			printf("\t\t\t\t\t该书已被清除\n");
			return ERROR;
		}
		else if(bor->Existingstock == 0)
		{
			printf("\t\t\t\t\t该书已被借完\n");
			return ERROR;
		}
		else
		{
			bor->Existingstock--;
			printf("\t\t\t\t\t你已经成功借走该书\n");
			printf("\t\t\t\t|  书号  |\t书名\t|\t作者\t|  现存  |  库存  |\n");
			printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
			SaveBooks();//保存数据 
		}		
	} 
}

void RetBooks(void)
{
	LBook *ret = NULL;
	ret = Choose();//选择书籍
	ret->Existingstock++;
	printf("\t\t\t\t\t你已经成功归还该书\n");
	printf("\t\t\t\t|  书号  |\t书名\t|\t作者\t|  现存  |  库存  |\n");
	printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", ret->Booknumber, ret->Bookname, ret->Author, ret->Existingstock, ret->Totalstock);
	SaveBooks();//保存数据 
} 

void PrintBooks(void)
{
	extern LBook *head, *tail;
	LBook *pos = head->next;
	printf("\t\t\t\t|  书号  |\t书名\t|\t作者\t|  现存  |  库存  |\n");
	while(pos != NULL) 
	{
		printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", pos->Booknumber, pos->Bookname, pos->Author, pos->Existingstock, pos->Totalstock);
		pos = pos->next;
	}
	printf("\n");
}
