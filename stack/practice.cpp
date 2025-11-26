#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {2, 7, 8, 4, 1, 9, 6};
    int n = arr.size();
    vector<int> ans(n, -1);
    stack <int> st;
    for(int i=0; i<2*n; i++)
    {
        int num = i%n;
        while(!st.empty() && arr[st.top()] < arr[num])
        {
            ans[st.top()] = arr[num];
            st.pop();
        }
        
        if(i<n)
        {
            st.push(i);
        }
        
        
    }

    for(auto i : ans)
    {
        cout << i << "  ";
    }

}