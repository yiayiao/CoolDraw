#pragma once
class CCurve
{
public:
	double a,b,c,d,e,f ;	//ϵͳ���ߵ�һЩ����
	char str[200];		//�Լ������ߵĲ���
	COLORREF m_color;
	int rank;			//rankΪ������ʾ�Լ��ĺ���
	int m_weight;
	CCurve(double a,double b,double c,COLORREF m_color, int m_weight,int rank);
	CCurve(double a,double b,double c,double d,double e,double f);
	CCurve(char a[200],COLORREF m_color,int m_weight);
	CCurve(void);
	~CCurve(void);


};

