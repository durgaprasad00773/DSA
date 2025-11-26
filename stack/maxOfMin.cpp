#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> maxOfMin(vector<int>& arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);
    stack <int> st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
        {
            int index = st.top();
            st.pop();
            if(st.empty())
            {
                int range = i;
                ans[range - 1] = max(ans[range-1], arr[index]);
            }
            else{
                int range = i-st.top()-1;
                ans[range - 1] = max(ans[range-1], arr[index]);
            }
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int index = st.top();
        st.pop();
        if(st.empty())
        {
            int range = n;
            ans[range - 1] = max(ans[range-1], arr[index]);
        }
        else{
            int range = n-st.top()-1;
            ans[range - 1] = max(ans[range-1], arr[index]);
        }
    }
    for(int i=n-2; i>=0; i--)
    {
        if(ans[i+1]>ans[i])
        {
            ans[i] = ans[i+1];
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> ans = maxOfMin(arr);
    for( int i: ans)
    {
        cout << i << "  ";
    }
}