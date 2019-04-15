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
LBookList CreateLibrary(void);											//创建书库
Status Warehousing(void);												//采编入库 
Status DeleteBook(void);												//删除书籍 
void SaveBooks(void);													//保存数据
void GetData(void);														//获取数据 
Status UserChangeInformation(void);										//改变书籍信息 
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 
