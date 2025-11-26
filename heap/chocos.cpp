#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maximum(int arr[], int n, int time)
{
    priority_queue<int> p;
    for(int i=0; i<n; i++)
    {
        p.push(arr[i]);
    }
    long long int ans = 0;
    while(time)
    {
        int temp = p.top();
        p.pop();
        ans += temp;
        temp = temp/2;
        p.push(temp);
        time--;
    }
    return ans % 1000000007;
}
int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int time = 5;

    cout << maximum(arr, n, time);
}