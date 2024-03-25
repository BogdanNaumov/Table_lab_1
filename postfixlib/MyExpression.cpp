#include "MyExpression.h"
TArithmeticExpression::TArithmeticExpression(string infx) : infix(infx)
{

    priority['+'] = priority['-'] = 1;
    priority['*'] = priority['/'] = 2;

    ToPostfix();
}

void TArithmeticExpression::Parse()
{
    for (char c : infix)
    {
        lexems.push_back(c);
    }
}

void TArithmeticExpression::ToPostfix()
{
    Parse();
    TStack<char> st(60);
    char stackItem;
    int count = 0;
    char item;
    int k = 0;
    while (count < lexems.size())
    {

        item = lexems[count];
        switch (item) {
        case '(':
            st.Push(item);
            break;
        case ')':
            stackItem = st.Pop();
            while (stackItem != '(') {
                postfix += stackItem;
                stackItem = st.Pop();
            }
            
            break;
        case '+': case '-': case '*': case '/':
            while (!st.IsEmpty()) {
                stackItem = st.Pop();
                if (priority[item] <= priority[stackItem])
                    postfix += stackItem;
                else {
                    st.Push(stackItem);
                    break;
                }
            }
            st.Push(item);
            break;
        default:
            string s = "";
            while ((item != ')') &&(item != '(')&&(item != '+') && (item != '-' )&& (item != '/' )&&( item != '*' )&& (item != ' ')&& count < lexems.size())
            {
                s += item;
                
                count++;
                if(count < lexems.size())
                    item = lexems[count];
                
            }

            operands[k]= stod(s);
            postfix += to_string(k);
            
            k++;
            count--;

        }
        count++;
    }
    while (!st.IsEmpty()) {
        stackItem = st.Pop();
        postfix += stackItem;

    }

}

string TArithmeticExpression::GetPostfix() 
{
    string s = "";
    int k = 0;
    for (char i : postfix)
    {
        switch (i) {
        case '+': case '-': case '*': case '/':
            s += i;
            break;
        default:

            s += to_string(operands[k]);
            k++;

        }
        
    }
    return s;
}

vector<char> TArithmeticExpression::GetOperands() const
{
    vector<char> op;
    for (const auto& item : operands)
        op.push_back(item.first);
    return op;
}

double TArithmeticExpression::Calculate()
{

    TStack<double> st(60);
    double leftOperand, rightOperand;
    int k = 0;
    for (char lexem : postfix)
    {

        switch (lexem)
        {
        case '+':
            rightOperand = st.Pop();
            
            leftOperand = st.Pop();
            st.Push(leftOperand + rightOperand);
            break;

        case '-':
            rightOperand = st.Pop();
            leftOperand = st.Pop();
            st.Push(leftOperand - rightOperand);
            break;
        case '*':
            rightOperand = st.Pop();
            leftOperand = st.Pop();
            st.Push(leftOperand * rightOperand);
            break;
        case '/':
            rightOperand = st.Pop();
            leftOperand = st.Pop();
            st.Push(leftOperand / rightOperand);
            break;
        case'(':case')':
            break;
        default:
            st.Push(operands[k]);
            k++;
            
        }
        
    }
    return st.Pop();
}
