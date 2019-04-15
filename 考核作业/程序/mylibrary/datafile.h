/***************************************************************************************
 *	File Name				:	datafile.h
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
#ifndef DATAFILE_H_INCLUDED
#define DATAFILE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "library.h"

/**************************************************************
*	Macro Define Section
**************************************************************/



/**************************************************************
*	Struct Define Section
**************************************************************/ 
LBookList CreateLibrary(void);											//�������
Status Warehousing(void);												//�ɱ���� 
Status DeleteBook(void);												//ɾ���鼮 
void SaveBooks(void);													//��������
void GetData(void);														//��ȡ���� 
Status UserChangeInformation(void);										//�ı��鼮��Ϣ 
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 
