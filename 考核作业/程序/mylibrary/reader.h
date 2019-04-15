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
    int Id;//ѧ�� 
    char Name;//���� 
    char *Academy;//ѧԺ 
    char *Book[60];//������Щ�� 
    int KeepBook;//���˶����� 
    struct reader *pre;
    struct reader *next;
} LReader, *LReaderList;


/**************************************************************
*	Prototype Declare Section
**************************************************************/ 


void LeadInterface(void);										//����������ʾ
void ReaderOperation();											//�Ķ��ߵĲ��� 
LReaderList CreateReaderList(void);
void AddReaders(void);

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 
