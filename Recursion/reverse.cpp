#include <bits/stdc++.h> 
using namespace std;

void insert(int x, stack<int> &st)
{
    if(st.empty())
    {
        st.push(x);
        return ;
    }

    int temp = st.top();
    st.pop();
    insert(x, st);
    st.push(temp);
}
void rev(stack<int> &st)
{
    //base condition
    if(st.empty())
    {
        return ;
    }

    int element = st.top();
    st.pop();

    rev(st);

    insert(element, st);


}
int main()
{
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);

    rev(st);

    while(!st.empty())
    {
        cout << st.top() << "  ";
        st.pop(); 
    }
}