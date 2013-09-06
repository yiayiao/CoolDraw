#include "stdafx.h"
#include "Calculat.h"

#include <cstring>
#include <stack>
#include <vector>
#include <cmath>

#define ADD	2
#define MUL	3
#define DIV 10
#define SUB 4
#define POW 5
#define SIN 6
#define COS 7
#define FAN 8
#define KUO 9
#define OPERATOR int

Calculat::Calculat(void)
{
}

Calculat::~Calculat(void)
{
}


struct Node		//
{
	bool flag;	//标识是运算符还是操作数
	double  num;
	OPERATOR ope;
	Node(double num)
	{
		this->num = num;
		flag = 1;
	}
	Node(OPERATOR ope)
	{
		this->ope = ope;
		flag = 0;
	}
};
double Calculat::solve(char str[],double x,bool& flag)
{
	for(int i=0;i<strlen(str);i++)
	{
		if('A'<=str[i] && str[i]<='Z')
			str[i] = 'a' + str[i] - 'A';
	}
	if(strlen(str) == 0)	//公式长度为0
	{
		flag = FALSE;
		return 0;
	}
	
	char *key = str;
	std::stack<Node> oper;
	std::vector<Node> num;
	double tmp = 0 , m = 0;
	int ff = 0 , fkuo = 1;
	for(int i=0;i<strlen(key);i++)
	{
		if(key[i] == ' ')
			continue;
		if (!(key[i] >= '0' && key[i] <= '9') && key[i] != '.'
			&& key[i] != '+' && key[i] != '-' && key[i] != '*'
			&& key[i] != '/' && key[i] != '^' && key[i] != 's'
			&& key[i] != 'c' && key[i] != 't' && key[i] != 'l'
			&& key[i] != '(' && key[i] != ')' && key[i] != 'p'
			&& key[i] != 'e' && key[i] != 'a' && key[i] != 'x')
		{
			flag = FALSE;		//字符不合法
			return 0;
		}
		if(key[i] == '-' && ff == 0 && fkuo)	//'-'后为负数
		{
			oper.push(Node(FAN));
			continue;
		}
		fkuo = 1;
		//如果是操作数，直接放入vector 中
		if(key[i] == 'x')
		{
			if(ff != 0)
			{
				flag = false;
				return 0;
			}
			tmp = x;
			ff = 3;
		}
		else if(key[i] == 'p')
		{
			if(key[++i] != 'i' || ff != 0)
			{
				flag = FALSE;
				return 0;
			}
			tmp = acos(-1);
			ff = 3;
		}
		else if(key[i] == 'e')
		{
			if(ff != 0)
			{
				flag = FALSE;
				return 0;
			}
			tmp = 2.718281828459;
			ff = 3;
		}
		else if( (key[i] >= '0' && key[i]<='9') || key[i] =='.')
		{
			if(ff == 3 || (key[i] == '.' && ff != 1) )
			{
				return FALSE;
				return 0;
			}
			if(key[i] == '.')	//小数
			{
				ff = 2;
				m = 0.1;
				continue;
			}
			if(ff != 2)
			{
				tmp = tmp*10 + key[i] - '0';
				ff = 1;
			}
			else
			{
				tmp += (key[i] - '0')*m;
				m /= 10;
			}
		}
		else   //为操作符,运行栈的处理
		{
			if(ff != 0)
			{
				num.push_back(Node(tmp));
				tmp = ff = 0;
			}
			if(key[i] == '(')
			{
				if(key[i+1] == ')')
				{
					flag = false;
					return 0;
				}
				oper.push(Node(KUO));
			}
			else if(key[i] == '+' || key[i] == '-')
			{
				while(!oper.empty() && oper.top().ope!=KUO)
				{
					num.push_back(oper.top());
					oper.pop();
				}
				if(key[i] == '+') 
					oper.push(Node(ADD));
				else 
					oper.push(Node(SUB));
			}
			else if(key[i] == '/' || key[i] == '*')
			{
				while(!oper.empty() && oper.top().ope!=KUO 
						&& oper.top().ope!=ADD && oper.top().ope!=SUB)
				{
					num.push_back(oper.top());
					oper.pop();
				}
				if(key[i] == '*')
					oper.push(Node(MUL));
				else
					oper.push(Node(DIV));
			}
			else if(key[i] == '^')
			{
				while(!oper.empty() && oper.top().ope!=KUO 
						&& oper.top().ope!=ADD && oper.top().ope!=SUB
						&& oper.top().ope!=MUL && oper.top().ope!=DIV)
				{
					num.push_back(oper.top());
					oper.pop();
				}
				oper.push(Node(POW));
			}
			else if(key[i] == 's' || key[i] == 'c')
			{
				//cout<<key[i]<<key[i+1]<<key[i+2]<<endl;
				if((key[i]=='s' && key[i+1]!='i' && key[i+2]!='n') || 
					(key[i]=='c' && key[i+1]!='0' && key[i+2]!='s'))
				{
					flag = FALSE;
					return 0;
				}
				while(!oper.empty() && oper.top().ope!=KUO 
						&& oper.top().ope!=ADD && oper.top().ope!=SUB
						&& oper.top().ope!=MUL && oper.top().ope!=DIV
						&& oper.top().ope!=POW && oper.top().ope!=FAN
						&& oper.top().ope!=SIN && oper.top().ope!=COS)
				{
					num.push_back(oper.top());
					oper.pop();
				}
				if(key[i] == 's')
					oper.push(Node(SIN));
				else
					oper.push(Node(COS));
				i+=2;
			}
			else if(key[i] == ')')
			{
				fkuo = false;
				while(!oper.empty() && oper.top().ope != KUO)
				{
					num.push_back(oper.top());
					oper.pop();
				}
				if(oper.empty())
				{
					flag = FALSE;
					return 0;
				}
				oper.pop();
			}
			else
			{
				flag = FALSE;
				return 0;
			}
		}
	}
	if(ff != 0)
		num.push_back(tmp);
	while(!oper.empty())
	{
		if(oper.top().ope == KUO)
		{
			flag = false;
			return 0;
		}
		num.push_back(oper.top());
		oper.pop();
	}
	
	std::stack<double> ans;
	double a,b;
	for(int i=0;i<num.size();i++)
	{
		if(num[i].flag)
		{
			ans.push(num[i].num);
		}
		else
		{
			int ope = num[i].ope;
			if(ope == ADD || ope == SUB || ope == POW || ope == MUL || ope == DIV)
			{
				if(ans.size() < 2)
				{
					flag = FALSE;
					return 0;
				}
				a = ans.top(), ans.pop();
				b = ans.top(), ans.pop();
			}
			else
			{
				if(ans.size() < 1)
				{
					flag = FALSE;
					return 0;
				}
				a = ans.top(), ans.pop();
			}
			switch(ope)
			{
				case ADD:
					ans.push(a + b);
					break;
				case SUB:
					ans.push(b - a);
					break;
				case MUL:
					ans.push(a * b);
					break;
				case DIV:
					ans.push(b / a);
					break;
				case SIN:
					ans.push(sin(a));
					break;
				case COS:
					ans.push(cos(a));
					break;
				case FAN:
					ans.push(-a);
					break;
				case POW:
					ans.push(pow(b*1.0 , a*1.0));
					break;
				default: break;
			}
		}
	}
	double fans = ans.top();
	ans.pop();
	if(ans.size()>0)
	{
		flag = FALSE;
		return 0;
	}
	//cout<<"ans:"<<fans<<endl;
	flag = TRUE;
	return fans;
}