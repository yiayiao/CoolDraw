#pragma once
class CCurve
{
public:
	double a,b,c,d,e,f ;	//系统曲线的一些参数
	char str[200];		//自己的曲线的参数
	COLORREF m_color;
	int rank;			//rank为负数表示自己的函数
	int m_weight;
	CCurve(double a,double b,double c,COLORREF m_color, int m_weight,int rank);
	CCurve(double a,double b,double c,double d,double e,double f);
	CCurve(char a[200],COLORREF m_color,int m_weight);
	CCurve(void);
	~CCurve(void);


};

