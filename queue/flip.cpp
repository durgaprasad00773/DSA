#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int flip(vector<bool> arr, int k)
{
    int n = arr.size();
    queue <int> q;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(!q.empty() && q.front() < i)
        {
            q.pop();
        }
        if(q.size()%2 == arr[i])
        {
            if(i+k-1 >= n)
            {
                return -1;
            }
            q.push(i+k-1);
            ans++;
        }
    }
    return ans;
}
int main()
{
    vector<bool> arr = {0, 1, 0, 1};
    int k = 2;
    cout << flip(arr, k);
}