// ArithmeticFactory.cpp: implementation of the ArithmeticFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GenerateArithmetic.h"
#include "ArithmeticFactory.h"
#include <time.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ArithmeticFactory::ArithmeticFactory()
{
	m_nCurMultiCount = 0;
}

ArithmeticFactory::~ArithmeticFactory()
{

}

void ArithmeticFactory::Init(THEME_PROPERTY* property)
{
	m_nCountEachUnit	= property->nCountEachUnit;
	m_nUnitCount = property->nUnitCount;

	m_nMultiCountEachUnit = property->nMultiCountEachUnit;
	m_nNumberMax = property->nNumberMax;
	m_nNumberMin = property->nNumberMin;
	m_nResultMax = property->nResultMax;
	m_nResultMin = property->nResultMin;	
	m_nDegree    = property->nDegree;

	m_nMDCountEachUnit = property->nMDCountEachUnit;
	m_nMDNumberMax = property->nMDNumberMax;
	m_nMDNumberMin = property->nMDNumberMin;
	m_nMDResultMax = property->nMDResultMax;
	m_nMDResultMin = property->nMDResultMin;	
	m_nMDDegree    = property->nMDDegree;

	time_t t;
	srand((unsigned) time(&t));
}

void ArithmeticFactory::Run()
{
	char sFileName[MAX_PATH] = "小学生算术练习题.doc";
	char sResultFileName[MAX_PATH] = "答案.doc";
	FILE* pFile = fopen(sFileName, "w");
	FILE* pFileResult = fopen(sResultFileName, "w");
	if (pFile != NULL && pFileResult != NULL) {
		for (int i = 1; i < m_nUnitCount+1; i ++) {
			char sLine[256] = "";
			sprintf(sLine, "单元%d\n", i);
			fwrite(sLine, 1, strlen(sLine), pFile);
			fwrite(sLine, 1, strlen(sLine), pFileResult);

			m_nCurMultiCount = 0;
			//计算加减法的行数
			int row = (m_nCountEachUnit - m_nMDCountEachUnit) / 2;
			for (int j = 0; j < row; j ++) {
				char sTheme[256] = "";
				char sResult[256] = "";
				GenerateTheme(sTheme, sResult);
				strcat(sTheme, "\t\t\t\t\t\t\t\t");
				strcat(sResult, "\t\t");

				fwrite(sTheme, 1, strlen(sTheme), pFile);
				fwrite(sResult, 1, strlen(sResult), pFileResult);

				GenerateTheme(sTheme, sResult);
				strcat(sTheme, "\n");
				strcat(sResult, "\t\t");

				fwrite(sTheme, 1, strlen(sTheme), pFile);
				fwrite(sResult, 1, strlen(sResult), pFileResult);
				OutputDebugStringA(sTheme);
			}

			//计算乘除法的行数
			row = m_nMDCountEachUnit / 2;
			for (j = 0; j < row; j ++) {
				char sTheme[256] = "";
				char sResult[256] = "";
				GenerateThemeMD(sTheme, sResult);
				strcat(sTheme, "\t\t\t\t\t\t\t\t");
				strcat(sResult, "\t\t");
				
				fwrite(sTheme, 1, strlen(sTheme), pFile);
				fwrite(sResult, 1, strlen(sResult), pFileResult);
				
				GenerateThemeMD(sTheme, sResult);
				strcat(sTheme, "\n");
				strcat(sResult, "\t\t");
				
				fwrite(sTheme, 1, strlen(sTheme), pFile);
				fwrite(sResult, 1, strlen(sResult), pFileResult);
				OutputDebugStringA(sTheme);
			}

			strcpy(sLine, "\n\n");
			fwrite(sLine, 1, strlen(sLine), pFile);
			fwrite(sLine, 1, strlen(sLine), pFileResult);
		}
	}
	fclose(pFile);
}

void ArithmeticFactory::GenerateTheme(char* pTheme, char* pResult)
{
	strcpy(pTheme, "");
	strcpy(pResult, "");
	int nMulti = 1;
	if (m_nCurMultiCount < m_nMultiCountEachUnit) {
		nMulti= Rand(1, 3);
		if (nMulti == 2) {
			m_nCurMultiCount ++;
		}
	}
	int nArithmetic[2] = {Rand(1, 3),Rand(1, 3)};
	int nNumber[3];
	int nResult=0;
	int nLoopNum;
	BOOL bSucceed = FALSE;
	BOOL bRepeat = FALSE;

	while (bSucceed==FALSE) {
		nArithmetic[0]	= Rand(1,3);
		nArithmetic[1]	= Rand(1,3);
		nLoopNum		= 0;
		
		for (int n = 0; n < nMulti; n ++) {
			while (nLoopNum <= 10) {
				int nNumberTemp;
				if (n == 0) {
					nNumber[n] = Rand(m_nNumberMin, m_nNumberMax+1);
					nNumberTemp = nNumber[n];
				} else {
					nNumberTemp = nResult;
				}
				nNumber[n+1] = Rand(m_nNumberMin, m_nNumberMax+1);
				if ((n ==0) && !CheckDegree(nNumberTemp, nNumber[n+1], nArithmetic[n])) {
					continue;					
				}
				if (nArithmetic[n] == 1) { //加法
					nResult = nNumberTemp + nNumber[n+1];
				} else if (nArithmetic[n] == 2) {  //减法
					nResult = nNumberTemp - nNumber[n+1];
				}
				//判断结果
				if (nResult >= m_nResultMin && nResult <= m_nResultMax) {
					if (n == nMulti -1) {
						bSucceed = TRUE;
					}					
					break;
				}
				nLoopNum ++;
			}
			if (bSucceed == TRUE) {
				break;
			}
			if (bRepeat == TRUE) {
				break;		
			}
		}
	}
	for (int n = 0; n < nMulti; n ++) {
		if (n == 0) {
			sprintf(pTheme, "%d", nNumber[0]);
		} 
		char str[1024] = "";
		if (nArithmetic[n] == 1) { //加法
			sprintf(str, " + %d", nNumber[n+1]);
		} else if (nArithmetic[n] == 2) {  //减法
			sprintf(str, " - %d", nNumber[n+1]);
		}
		strcat(pTheme, str);
	}
	strcat(pTheme, " = ");

	sprintf(pResult, "%d", nResult);
}

void ArithmeticFactory::GenerateThemeMD(char* pTheme, char* pResult)
{
	int n1 = Rand(m_nMDNumberMin, m_nMDNumberMax+1);
	int n2 = Rand(m_nMDNumberMin, m_nMDNumberMax+1);
	int n3 = n1 * n2;
	int mdType = Rand(1,3); //1为乘法，2为除法
	if (mdType == 1) {
		sprintf(pTheme, "%d × %d = ", n1, n2);
		sprintf(pResult, "%d", n3);
	} else {
		sprintf(pTheme, "%d ÷ %d = ", n3, n1);
		sprintf(pResult, "%d", n2);
	}
}

int ArithmeticFactory::Rand(int nMin, int nMax)
{	
	int n;
	while(1) {
		n = rand()%nMax;
		if (n >= nMin) {
			break;
		}
	}
	return n;
}

BOOL ArithmeticFactory::CheckDegree(int nNumber1, int nNumber2, int arithmetic)
{
	if (m_nDegree == 1) {
		return TRUE;
	}
	int nBit1 = nNumber1 % 10;
	int nBit2 = nNumber2 % 10;
	
	int nTen1 = (nNumber1 / 10) % 10;
	int nTen2 = (nNumber2 / 10) % 10;

	int nBitPlus = nBit1 + nBit2;		//个位
	int nTenPlus = nTen1 + nTen2;		//十位

	int nBitReduce = nBit1 - nBit2;		//个位
	int nTenReduce = nTen1 - nTen2;		//十位

	switch (m_nDegree) {
	case 2: {
		if (nBit1 == 0 || nBit2 == 0 || nBitReduce == 0 || (nTenReduce+nBitReduce/10) == 0) {
			return FALSE;
		}
		//各位上的相加在1-2之间
		if (arithmetic == 1) {
			//加法
			if (nBitPlus >= 1 && nBitPlus <= 4) {
				return TRUE;
			} 
		} else {
			//减法
			if (nBitReduce >= 1 && nBitReduce <= 4 ){
				return TRUE;
			} 
		}
		break;
			}
	case 3: {
		if (nBit1 == 0 || nBit2 == 0 || nBitReduce == 0 || (nTenReduce+nBitReduce/10) == 0) {
			return FALSE;
		}

		//各位上的相加在3-4之间
		if (arithmetic == 1) {
			//加法
			if (nBitPlus > 4 && nBitPlus <= 9) {
				return TRUE;
			} 
		} else {
			//减法
			if (nBitReduce >= 4 && nBitReduce <= 9 ){
				return TRUE;
			} 
		}
		break;
			}
	case 4: {
		if (nBit1 == 0 || nBit2 == 0 || nBitReduce == 0 || (nTenReduce+nBitReduce/10) == 0) {
			return FALSE;
		}

// 		if (n1 == 0 || n2 == 0) {
// 			return FALSE;
// 		}

		//各位上的相加在5-6之间
		if (arithmetic == 1) {
			//加法
			if (nBitPlus > 9 && nBitPlus <= 12) {
				return TRUE;
			} 
		} else {
			//减法
			if (nBitReduce >= -4 && nBitReduce <= -1 ){
				return TRUE;
			} 
		}
		break;
			}
	case 5: {
		if (nBit1 == 0 || nBit2 == 0 || nBitReduce == 0 || (nTenReduce+nBitReduce/10) == 0) {
			return FALSE;
		}

		//各位上的相加在7-8之间
		if (arithmetic == 1) {
			//加法
			if (nBitPlus > 12 && nBitPlus <= 15) {
				return TRUE;
			} 
		} else {
			//减法
			if (nBitReduce >= -9 && nBitReduce <= -4 ){
				return TRUE;
			} 
		}
		break;
			}
	default: {
		//消除0结尾的数字

	}

	}
	char str[256] = "";
	char sArith[2] = "";
	if (arithmetic==1) {
		strcpy(sArith, "+");
	} else {
		strcpy(sArith, "-");
	}
	sprintf(str, "%d %s %d\n", nNumber1, sArith, nNumber2);
	OutputDebugStringA(str);
	return FALSE;
}