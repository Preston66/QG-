/***************************************************************************************
 *	File Name				:	library.h
 *	CopyRight				:	2019 QG Studio  
 *	SYSTEM					:   win10
 *	Create Data				:	2019.3.20
 *	Author/Corportation		:	Preston
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**************************************************************
*	Macro Define Section
**************************************************************/



/**************************************************************
*	Struct Define Section
**************************************************************/ 

// define struct of linked list
typedef struct LBook { 
	int Booknumber; 
	char Bookname[60];
	char Author[40];
	int Existingstock;
	int Totalstock;
	struct LBook *pre;
  	struct LBook *next; 
} LBook, *LBookList;

// define Status
typedef enum Status { 
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/ 

void strcutcpy(LBook *book1, LBook *book2);								//�ṹ�帳ֵ 
	
LBookList FindBooks(void);												//�����鼮 
LBook *Choose(void);													//ѡ���鼮 
LBookList *Choose1(void);
int IsBook(int way, char *key, LBook *pos);								//���ݴ���ķ�ʽ�ж��Ƿ����Ȿ��
void PrintBooks(void);													//��ӡ�鼮��Ϣ 
Status BorrowBooks(void);												//�����鼮 
LBook *BorrowBooks1(); 
void RetBooks(void);													//�����鼮 
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 
