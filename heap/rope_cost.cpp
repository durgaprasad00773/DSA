#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minimum(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> p;
    int n = arr.size();
    int ans = 0;
    if(n == 1)
    {
        return ans;
    }
    
    for(int i=0; i<n; i++)
    {
        p.push(arr[i]);
    }
    while(p.size() != 1)
    {
        int sum = p.top();
        p.pop();
        sum += p.top();
        p.pop();
        ans = ans+sum;
        p.push(sum);
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 2, 3, 6};
    cout << minimum(arr);
}