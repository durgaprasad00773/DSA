#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int last(vector<int> arr)
{
    int n = arr.size();
    priority_queue<int> p;
    for(int i=0; i<n; i++)
    {
        p.push(arr[i]);
    }

    while(p.size() != 1 && p.empty() != 1)
    {
        int x = p.top();
        p.pop();
        int y = p.top();
        p.pop();
        if(x != y)
        {
            p.push(x-y);
        }
    }

    if(p.empty())
    {
        return 0;
    }
    return p.top();

}
int main()
{
    vector<int> arr = {2,7,4,1,8,1};
    cout << last(arr);
}