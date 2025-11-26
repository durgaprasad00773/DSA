#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> span(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, 1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[i] >= arr[st.top()])
        {
            ans[i] = ans[i] + ans[st.top()];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = span(arr);
    for(auto i : ans)
    {
        cout << i << " ";
    }
}