#include "stdafx.h"
#include "Expression.h"

 
// 构造函数
Expression::Expression( string str ):
	expr(str),
	idx(0),
	err(0),
	Right(true)
{
	
}


 
// 外部接口
bool Expression::test()
{
	if(!word.empty())  // 已经test过了
	{
		return Right;
	}
 
	int err_num = word_analysis(word, expr);
	if (-1 == err_num)
	{
		Right = false;
	}
	else
	{
		// 词法正确，进行语法分析
		Next();
		E();
		if (sym == 0 && err == 0)  // 注意要判断两个条件
			Right = true;
		else
			Right = false;
	}
	return Right;
}
 
// 外部接口
double Expression::calculate()
{
	if (test())
	{
		return expCalculate(getPostfix(word));
	}
	else
	{
		exit(0);
	}
}
 
/*--------------------------------词法分析----------------------------*/
int Expression::word_analysis(vector<pair<string, int> >& word, const string expr)
{
	for(int i=0; i<expr.length(); ++i)
	{
		// 如果是 + - x ÷ ( )
		if(expr[i] == '(' || expr[i] == ')' || expr[i] == '+' 
			|| expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
		{
			string tmp;
			tmp += (expr[i]);
			switch (expr[i])
			{
			case '+':
				word.push_back(make_pair(tmp, 1));
				break;
			case '-':
				word.push_back(make_pair(tmp, 2));
				break;
			case '*':
				word.push_back(make_pair(tmp, 3));
				break;
			case '/':
				word.push_back(make_pair(tmp, 4));
				break;
			case '(':
				word.push_back(make_pair(tmp, 6));
				break;
			case ')':
				word.push_back(make_pair(tmp, 7));
				break;
			}
		}
		// 如果是数字开头
		else if(expr[i]>='0' && expr[i]<='9')
		{
			string tmp;
			while(expr[i]>='0' && expr[i]<='9')
			{
				tmp += (expr[i]);
				++i;
			}
			if(expr[i] == '.')
			{
				++i;
				if(expr[i]>='0' && expr[i]<='9')
				{
					tmp += ('.');
					while(expr[i]>='0' && expr[i]<='9')
					{
						tmp += (expr[i]);
						++i;
					}
				}
				else  
				{
					return -1;  // .后面不是数字，词法错误
				}
			}
			word.push_back(make_pair(tmp, 5));
			--i;
		}
		// 如果以.开头
		else  
		{
			return -1;  // 以.开头，词法错误
		}
	}
	return 0;
}
 
/*--------------------------------语法分析----------------------------*/
// 读下一单词的种别编码
void Expression::Next()
{   
	if(idx < word.size())
		sym = word[idx++].second;
	else
		sym = 0;
}
 
// E → T { +T | -T } 
void Expression::E()
{
	T();
	while(sym == 1 || sym == 2)
	{
		Next();
		T();
	}
}
 
// T → F { *F | /F } 
void Expression::T()
{
	F();
	while(sym == 3 || sym == 4)
	{
		Next();
		F();
	}
}
 
// F → (E) | d
void Expression::F()
{
	if (sym == 5)
	{
		Next();
	}
	else if(sym == 6)
	{
		Next();
		E();
		if (sym == 7)
		{
			Next();
		}
		else
		{
			err = -1;
		}
	}
	else
	{
		err = -1;
	}
}
 
/*--------------------------------求值部分----------------------------*/
int Expression::prior(int sym)
{
	switch (sym)
	{
		case 1:
		case 2:
			return 1;
		case 3:
		case 4:
			return 2;
		default:
			return 0;
	}
}
 
bool Expression::isOperator(int sym)
{
	switch (sym)
	{
		case 1:
		case 2:
		case 3:
		case 4:
			return true;
		default:
			return false;
	}
}
 
vector<pair<string,int> > Expression::getPostfix( const vector<pair<string,int> >& expr)
{
	vector<pair<string, int> > output;  // 输出
	stack<pair<string, int> > s;        // 操作符栈
	for(int i=0; i<expr.size(); ++i)
	{
		pair<string, int> p = expr[i];
		if(isOperator(p.second))
		{
			while(!s.empty() && isOperator(s.top().second) && prior(s.top().second)>=prior(p.second))
			{
				output.push_back(s.top());
				s.pop();
			}
			s.push(p);
		}
		else if(p.second == 6)
		{
			s.push(p);
		}
		else if(p.second == 7)
		{
			while(s.top().second != 6)
			{
				output.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else
		{
			output.push_back(p);
		}
	}
	while (!s.empty())
	{
		output.push_back(s.top());
		s.pop();
	}
	return output;
}
 
void Expression::popTwoNumbers( stack<double>& s, double& first, double& second )
{
	first = s.top();
	s.pop();
	second = s.top();
	s.pop();
}
 
double Expression::stringToDouble( const string& str )
{
	double d;
	stringstream ss;
	ss << str;
	ss >> d;
	return d;
}
 
double Expression::expCalculate( const vector<pair<string,int> >& postfix )
{
	double first,second;
	stack<double> s;
	for(int i=0; i<postfix.size(); ++i)
	{
		pair<string,int> p = postfix[i];
		switch (p.second)
		{
		case 1:
			popTwoNumbers(s, first, second);
			s.push(second+first);
			break;
		case 2:
			popTwoNumbers(s, first, second);
			s.push(second-first);
			break;
		case 3:
			popTwoNumbers(s, first, second);
			s.push(second*first);
			break;
		case 4:
			popTwoNumbers(s, first, second);
			s.push(second/first);
			break;
		default:
			s.push(stringToDouble(p.first));
			break;
		}
	}
	double result = s.top();
	s.pop();
	return result;
}


int main()
{	
	Expression e("(1.5+2.5)*2+0.53");
	if(e.test())   // 判断表达式是否合法
		cout << e.calculate() << endl;
	return 0;
}