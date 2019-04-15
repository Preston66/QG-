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
//	int tm_sec;//����Ŀǰ������������ΧΪ0~59��������61��
//	int tm_min;//����Ŀǰ��������ΧΪ0~59
//	int tm_hour;//����ҹ�����ʱ������ΧΪ0~23
//	int tm_mday;//����Ŀǰ�·ݵ���������ΧΪ01~21
//	int tm_mon;//����Ŀǰ���·ݣ���һ�·����𣬷�ΧΪ0~11
//	int tm_year;//�����1900���������������
//	int tm_wday;//����һ���ڵ�������������һ���𣬷�ΧΪ0~6
//	int tm_yday;//����ӽ���1��1�������������������ΧΪ0~365
//	int tm_isdst;//�����չ����ʱ������ 
//} mytime;
 
typedef struct log
{ 
    char *Operation[100];//������¼ 
    struct log *pre;
    struct log *next;
} Log, *LogList; 
 
 /**************************************************************
*	Prototype Declare Section
**************************************************************/ 

void PrintfTmie(void);												//��ӡʱ�� 
void OperationLog(int option);										//������¼ 
 
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif 
