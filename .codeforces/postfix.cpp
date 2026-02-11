#include <iostream>
#include <stack>
using namespace std;
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

bool isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

int main()
{
    
    string prefix = "a+b*c-d";
    stack<char> operators;
    string postfix="";

    for(char i : prefix)
    {
        if(isOperand(i))
        {
            postfix+=i;
        }

        else if(i == '(')
        {
            operators.push(i);
        }

        else if(i == ')')
        {
            while(!operators.empty() && operators.top() != '(')
            {
                postfix+=operators.top();
                operators.pop();
            }
            operators.pop();
        }


        else if(i == '*'||i=='+'||i=='-'||i=='/')
        {
            while(!operators.empty() && precedence(operators.top()) > precedence(i))
            {
                postfix+=operators.top();
                operators.pop();
            }
            operators.push(i);
        }

    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    cout << postfix;


}
