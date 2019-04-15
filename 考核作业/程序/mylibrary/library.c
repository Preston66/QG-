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
	int finding = 1;//���ұ�־ 
	int c;
	LBookList Lfind = NULL;
	LBook *Sbook = NULL;
	printf("\t\t\t\t\t����Ҫ��ʲô��\n");
	while(finding) 
	{
		Lfind = Choose();
		Sbook = Lfind->next;
		if (Sbook == NULL) 
		{
			printf("\t\t\t\t\tû���ҵ����鼮\n");
		} 
		else 
		{			
			printf("\t\t\t\t\t�ɹ����ҵ�����鼮\n");
			printf("\t\t\t\t\t���\t����\t����\t\t�ִ�\t���\n");
			while(Sbook)
			{
				printf("\t\t\t\t\t%08d%8s%8s%8d\t%8d\n", Sbook->Booknumber, Sbook->Bookname, Sbook->Author, Sbook->Existingstock, Sbook->Totalstock);
				Sbook = Sbook->next;
			}
		}
		printf("\t\t\t\t\t0 �˳�������������\n");
		scanf("%d", &c);
		if (c == 0) 
		{
			finding = 0;
		}
		printf("\n");
	}
	return Lfind;
}

LBook *Choose(void)//�������� 
{
	char key[60] = {0};
	int way, booknumber;
//	int Ishead = 1;//��ͷ���:1:�Ǳ�ͷ;0:���Ǳ�ͷ 
	extern LBook *head, *tail;
	LBook *pos = head, *r, *s;
	LBookList Lfind = NULL;
	Lfind = (LBook *)malloc(sizeof(LBook));//�����������洢�ҵ�������鼮 
	Lfind->next = NULL;
//	find = (LBook *)malloc(sizeof(LBook));
	r = Lfind;
	printf("\t\t\t\t\t1:���;2:����;3:����\n");
	printf("\t\t\t\t\t����ͨ��ʲô��ʽ�����鼮\n\t\t\t\t\t");
	scanf("%d",&way);
	while(way<=0 || way>=4)
	{
		printf("\t\t\t\t\t����������\n");
		scanf("%d",&way);		
	}
	printf("\t\t\t\t\t������ؼ���\n\t\t\t\t\t");
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
		case 1://ͨ����Ų��� 
			Booknumber = atoi(key);
			if(Booknumber == pos->Booknumber)
				return 0;
			break;
		case 2://ͨ���������� 
			return strcmp(key, pos->Bookname);
			break;
		case 3://ͨ�����߲��� 
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
	Lfind = Choose();//ѡ���鼮
	bor = Lfind->next;
	if(bor->next == NULL)//���ֻ�ҵ�һ�� 
	{
		if(bor->Totalstock == 0)
		{
			printf("\t\t\t\t\t�����ѱ����\n");
			return ERROR;
		}
		else if(bor->Existingstock == 0)
		{
			printf("\t\t\t\t\t�����ѱ�����\n");
			return ERROR;
		}
		else
		{
//			bor->Existingstock--;
//			printf("\t\t\t\t\t���Ѿ��ɹ����߸���\n");
//			printf("\t\t\t\t|  ���  |\t����\t|\t����\t|  �ִ�  |  ���  |\n");
//			printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
//			SaveBooks();//��������
			return bor; 
		}		
	}
	else
	{
		printf("\t\t\t\t\t�ɹ����ҵ�����鼮\n");
		printf("\t\t\t\t\t���\t����\t����\t\t�ִ�\t���\n");
		
		while(bor)
		{
			printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
			bor = bor->next;
		}
		printf("\t\t\t\t\t��Ҫ���ı��飿\n");
		
		bor = NULL;
		bor = Choose();//�ٴ�ѡ���鼮
		if(bor->Totalstock == 0)
		{
			printf("\t\t\t\t\t�����ѱ����\n");
			return ERROR;
		}
		else if(bor->Existingstock == 0)
		{
			printf("\t\t\t\t\t�����ѱ�����\n");
			return ERROR;
		}
		else
		{
//			bor->Existingstock--;
//			printf("\t\t\t\t\t���Ѿ��ɹ����߸���\n");
//			printf("\t\t\t\t|  ���  |\t����\t|\t����\t|  �ִ�  |  ���  |\n");
//			printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
//			SaveBooks();//�������� 
			return bor;
		}		
	} 
}

Status BorrowBooks(void)
{
	LBookList Lfind = NULL;
	LBook *bor = NULL;
	Lfind = Choose();//ѡ���鼮
	bor = Lfind->next;
	if(bor->next == NULL)//���ֻ�ҵ�һ�� 
	{
		if(bor->Totalstock == 0)
		{
			printf("\t\t\t\t\t�����ѱ����\n");
			return ERROR;
		}
		else if(bor->Existingstock == 0)
		{
			printf("\t\t\t\t\t�����ѱ�����\n");
			return ERROR;
		}
		else
		{
			bor->Existingstock--;
			printf("\t\t\t\t\t���Ѿ��ɹ����߸���\n");
			printf("\t\t\t\t|  ���  |\t����\t|\t����\t|  �ִ�  |  ���  |\n");
			printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
			SaveBooks();//�������� 
		}		
	}
	else
	{
		printf("\t\t\t\t\t�ɹ����ҵ�����鼮\n");
		printf("\t\t\t\t\t���\t����\t����\t\t�ִ�\t���\n");
		
		while(bor)
		{
			printf("\t\t\t\t\t%-8d%-8s%-8s%8d\t%8d\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
			bor = bor->next;
		}
		printf("\t\t\t\t\t��Ҫ���ı��飿\n");
		
		bor = NULL;
		bor = Choose();//�ٴ�ѡ���鼮
		if(bor->Totalstock == 0)
		{
			printf("\t\t\t\t\t�����ѱ����\n");
			return ERROR;
		}
		else if(bor->Existingstock == 0)
		{
			printf("\t\t\t\t\t�����ѱ�����\n");
			return ERROR;
		}
		else
		{
			bor->Existingstock--;
			printf("\t\t\t\t\t���Ѿ��ɹ����߸���\n");
			printf("\t\t\t\t|  ���  |\t����\t|\t����\t|  �ִ�  |  ���  |\n");
			printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", bor->Booknumber, bor->Bookname, bor->Author, bor->Existingstock, bor->Totalstock);
			SaveBooks();//�������� 
		}		
	} 
}

void RetBooks(void)
{
	LBook *ret = NULL;
	ret = Choose();//ѡ���鼮
	ret->Existingstock++;
	printf("\t\t\t\t\t���Ѿ��ɹ��黹����\n");
	printf("\t\t\t\t|  ���  |\t����\t|\t����\t|  �ִ�  |  ���  |\n");
	printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", ret->Booknumber, ret->Bookname, ret->Author, ret->Existingstock, ret->Totalstock);
	SaveBooks();//�������� 
} 

void PrintBooks(void)
{
	extern LBook *head, *tail;
	LBook *pos = head->next;
	printf("\t\t\t\t|  ���  |\t����\t|\t����\t|  �ִ�  |  ���  |\n");
	while(pos != NULL) 
	{
		printf("\t\t\t\t|%08d|\t%-8s|\t%-8s|%8d|%8d|\n", pos->Booknumber, pos->Bookname, pos->Author, pos->Existingstock, pos->Totalstock);
		pos = pos->next;
	}
	printf("\n");
}
