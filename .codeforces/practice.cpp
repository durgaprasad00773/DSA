#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> values;

    for (char c : postfix) {
        if (isdigit(c)) {
            values.push(c - '0'); // Convert char to int and push to stack
        } else {
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();

            switch(c) {
                case '+': values.push(val1 + val2); break;
                case '-': values.push(val1 - val2); break;
                case '*': values.push(val1 * val2); break;
                case '/': values.push(val1 / val2); break;
            }
        }
    }

    return values.top(); // The final result will be the only value in the stack
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result of postfix expression: " << result << endl;
    return 0;
}
