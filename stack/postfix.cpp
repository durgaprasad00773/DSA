#include <bits/stdc++.h>
using namespace std;
int precedence(char c)
{
    if(c == '+' || c == '-')
    return 1;
    if(c == '*' || c == '/')
    return 2;
    if(c == '^')
    return 3;
}
bool Rassociativity(char c)
{
    return c == '^';
}


int main()
{
    string s = "(A+B)*C-D^E^F";
    string ans;
    stack <char> st;
    for(char c : s)
    {
        if(isalnum(c))
        {
            ans.push_back(c);
        }

        else if(c == '(')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && (precedence(st.top()) > precedence(c) ||  (precedence(st.top()) == precedence(c) && !Rassociativity(c))) && st.top()!= '(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }


    cout << ans;
}