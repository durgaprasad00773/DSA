#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n = 143;
    vector<int> ans;
    int i = 0;
    while(n > 0) // i < arr.size()
    {
        if(arr[i] > n)
        {
            i++;
        }
        else
        {
            ans.push_back(arr[i]);
            n -= arr[i];
        }
    }

    for (auto i : ans)
    {
        cout << i << "  ";
    }
}