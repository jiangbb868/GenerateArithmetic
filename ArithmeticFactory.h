// ArithmeticFactory.h: interface for the ArithmeticFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARITHMETICFACTORY_H__D689AA97_DF28_4975_88F4_EC9E4C4EA7B2__INCLUDED_)
#define AFX_ARITHMETICFACTORY_H__D689AA97_DF28_4975_88F4_EC9E4C4EA7B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "def.h"
class ArithmeticFactory  
{
	int		m_nCountEachUnit;
	int		m_nUnitCount;
	int		m_nMultiCountEachUnit;
	int		m_nNumberMax;
	int		m_nNumberMin;
	int		m_nResultMax;
	int		m_nResultMin;
	int		m_nCurMultiCount;
	int		m_nDegree;

	int		m_nMDCountEachUnit;
	int		m_nMDNumberMax;
	int		m_nMDNumberMin;
	int		m_nMDResultMax;
	int		m_nMDResultMin;
	int		m_nMDCurMultiCount;
	int		m_nMDDegree;
public:
	ArithmeticFactory();
	virtual ~ArithmeticFactory();
	void Init(THEME_PROPERTY* property);
	void Run();
	void GenerateTheme(char* pTheme, char* sResult);
	void GenerateThemeMD(char* pTheme, char* pResult);
	int Rand(int nMin, int nMax);
	BOOL CheckDegree(int nNumber1, int nNumber2, int arithmetic);
};

#endif // !defined(AFX_ARITHMETICFACTORY_H__D689AA97_DF28_4975_88F4_EC9E4C4EA7B2__INCLUDED_)
