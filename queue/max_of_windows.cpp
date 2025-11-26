#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <climits>
using namespace std;
vector<int> maxi(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    deque<int> q;
    for(int i=0; i<k-1; i++)
    {
        if(q.empty())
        {
            q.push_back(i);
        }
        else
        {
            while(!q.empty() && arr[q.back()] < arr[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
    }
    for(int i=k-1; i<n; i++)
    {
        while(!q.empty() && arr[q.back()] < arr[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        while(!q.empty() && q.front() <= i-k)
        {
            q.pop_front();
        }
        ans.push_back(arr[q.front()]);
        

    }
    return ans;
}
int main()
{
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxi(arr, k);
    for(auto i : ans)
    {
        cout << i << "  ";
    }
}