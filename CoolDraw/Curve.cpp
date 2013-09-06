#include "stdafx.h"
#include "Curve.h"


CCurve::CCurve(void)
{
}


CCurve::~CCurve(void)
{
}

CCurve::CCurve(double a,double b,double c,COLORREF m_color, int m_weight,int rank)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->m_color = m_color;
	this->m_weight = m_weight;
	this->rank = rank;
	strcpy_s(this->str, "-1");
	d = e = f = 0;
}

CCurve::CCurve(char a[200],COLORREF m_color,int m_weight)
{
	strcpy_s(this->str, a);
	rank = -2;
	this->m_color = m_color;
	this->m_weight = m_weight;
}

CCurve::CCurve(double a,double b,double c,double d,double e,double f)
	:a(a),b(b),c(c),d(d),e(e),f(f)
{
}