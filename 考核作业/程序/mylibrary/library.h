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

void strcutcpy(LBook *book1, LBook *book2);								//结构体赋值 
	
LBookList FindBooks(void);												//查找书籍 
LBook *Choose(void);													//选择书籍 
LBookList *Choose1(void);
int IsBook(int way, char *key, LBook *pos);								//根据传入的方式判断是否是这本书
void PrintBooks(void);													//打印书籍信息 
Status BorrowBooks(void);												//借阅书籍 
LBook *BorrowBooks1(); 
void RetBooks(void);													//返还书籍 
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 
