#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n, int k1, int k2)
{
    int total = 0;
    priority_queue<int> p;
    priority_queue<int> q;
    for(int i=0; i<k1; i++)
    {
        p.push(arr[i]);
    }

    for(int i= 0; i< k2-1; i++)
    {
        q.push(arr[i]);
    }

    for(int i=k1; i<n; i++)
    {
        if(p.top() > arr[i])
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    for(int i=k2-1; i<n; i++)
    {
        if(q.top() > arr[i])
        {
            q.pop();
            q.push(arr[i]);
        }
    }

    while(q.size() != p.size())
    {
        total+=q.top();
        q.pop();
    }

    return total;
}

int main()
{
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k1 = 3;
    int k2 = 6;

   cout << sum(arr, n, k1, k2);

}