#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "..\postfixlib\MyExpression.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    string exprStr;
    cout << "Введите выражение :"<<endl;
    cin >> exprStr;
    TArithmeticExpression expr(exprStr);
    cout << "В постфиксной форме: " << expr.GetPostfix() << endl;
    vector<char> operands = expr.GetOperands();

    cout << expr.Calculate() << endl;

}