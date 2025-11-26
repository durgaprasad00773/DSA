#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> p;
    p.push(223);
    p.push(2300);
    p.push(23);
    p.push(2);
    p.push(3);
    p.push(223);
    p.push(2300);
    p.push(23);
    p.push(2);
    p.push(3);
    while(!p.empty())
    {
        cout << p.top() << "  ";
        p.pop();
    }

    cout << endl;
    

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(223);
    q.push(2300);
    q.push(23);
    q.push(2);
    q.push(3);
    while(!q.empty())
    {
        cout << q.top() << "  ";
        q.pop();
    }

}