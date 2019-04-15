/***************************************************************************************
 *	File Name				:	log.h
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
#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "datafile.h" 
#include "library.h"

/**************************************************************
*	Macro Define Section
**************************************************************/



/**************************************************************
*	Struct Define Section
**************************************************************/ 

//typedef struct tm {
//	int tm_sec;//代表目前秒数，正常范围为0~59，允许至61秒
//	int tm_min;//代表目前分数，范围为0~59
//	int tm_hour;//从午夜算起的时数，范围为0~23
//	int tm_mday;//代表目前月份的日数，范围为01~21
//	int tm_mon;//代表目前的月份，从一月份算起，范围为0~11
//	int tm_year;//代表从1900年算起至今的年数
//	int tm_wday;//代表一星期的日数，从星期一算起，范围为0~6
//	int tm_yday;//代表从今年1月1日算起至今的天数，范围为0~365
//	int tm_isdst;//代表日光借阅时间的旗标 
//} mytime;
 
typedef struct log
{ 
    char *Operation[100];//操作记录 
    struct log *pre;
    struct log *next;
} Log, *LogList; 
 
 /**************************************************************
*	Prototype Declare Section
**************************************************************/ 

void PrintfTmie(void);												//打印时间 
void OperationLog(int option);										//操作记录 
 
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 
