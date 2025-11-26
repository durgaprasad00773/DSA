#include <iostream>
#include<queue>
using namespace std;
class stack
{
    queue<int> q1;
    queue<int> q2;
    public:
    bool empty()
    {
        if(q1.empty())
        {
            return 1;
        }
        return 0;
    }
    void push(int x)
    {
        q1.push(x);
    }
    int pop()
    {
        if(q1.empty())
        {
            return -1;
        }
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    int peek()
    {
        if(q1.empty())
        {
            return -1;
        }
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q2.push(x);
        q1.pop();
         while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;

    }
};
int main()
{
    stack st;
    cout << st.empty();
}