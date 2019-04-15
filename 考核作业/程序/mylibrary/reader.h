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
#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "library.h"
#include "datafile.h"
#include "log.h"

/**************************************************************
*	Macro Define Section
**************************************************************/



/**************************************************************
*	Struct Define Section
**************************************************************/ 

typedef struct reader
{
    int Id;//学号 
    char Name;//名字 
    char *Academy;//学院 
    char *Book[60];//借了哪些书 
    int KeepBook;//借了多少书 
    struct reader *pre;
    struct reader *next;
} LReader, *LReaderList;


/**************************************************************
*	Prototype Declare Section
**************************************************************/ 


void LeadInterface(void);										//引导界面显示
void ReaderOperation();											//阅读者的操作 
LReaderList CreateReaderList(void);
void AddReaders(void);

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 
