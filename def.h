#ifndef _GENERATE_ARITHEMETIC_DEF_H_
#define _GENERATE_ARITHEMETIC_DEF_H_

typedef struct ThemeProperty {
	int		nNumberMin;
	int		nNumberMax;
	int		nResultMin;
	int		nResultMax;
	int     nDegree;
	int		nMultiCountEachUnit;
	int		nMDNumberMin;
	int		nMDNumberMax;
	int		nMDResultMin;
	int		nMDResultMax;
	int     nMDDegree;
	int		nMDCountEachUnit;
	int		nUnitCount;
	int		nCountEachUnit;
} THEME_PROPERTY,*PTHEME_PROPERTY;

#endif