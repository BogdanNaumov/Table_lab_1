#ifndef _MY_EXPRESSION_
#define _MY_EXPRESSION_
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
#include <vector>
#include "MyStack.h"
using namespace std;

class TArithmeticExpression
{
	string infix;
	string postfix;
	vector<char> lexems;
	map<char, int> priority;
	map<int, int> operands;
	void Parse();
	void ToPostfix();

public:
	TArithmeticExpression(string infx);
	string GetInfix() const 
	{
		return infix;
	}
	string GetPostfix();
	vector<char> GetOperands() const;
	double Calculate();//const map<char, double>& values);
};

#endif