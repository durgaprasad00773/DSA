#include <iostream>
#include <stack>
using namespace std;
class queue
{
    stack<int> st1;
    stack<int> st2;
    public:
    bool empty()
    {
        if(st1.empty() && st2.empty())
        {
            return 1;
        }
        return 0;
    }
    int peek()
    {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(empty())
        {
            return -1;
        }
        return st2.top();
    }

    void push(int x)
    {
        st1.push(x);
    }
    int pop()
    {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            
        }
        if(st2.empty())
        {
            return -1;
        }
        else{
            int a = st2.top();
            st2.pop();
            return a;
        }

    }
};
int main()
{
    queue q;
    q.push(23);
    cout << q.peek();
}