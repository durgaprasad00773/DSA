#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int rectangle(vector<int> &arr)
{
    int n = arr.size();
    stack <int> st;
    int index, ans = 0;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
        {
            index = st.top();
            st.pop();
            if(!st.empty())
            {
                ans = max(ans, arr[index]*(i-st.top()-1));
            }
            else{
                ans = max(ans, arr[index]*i);
            }
        }
        st.push(i);
    }
    while(!st.empty())
    {
        index = st.top();
        st.pop();
        if(!st.empty())
        {
            ans = max(ans, arr[index]*(n-st.top()-1));
        }
        else{
            ans = max(ans, arr[index]*n);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {2,1,5,6,2,3};
    cout <<  rectangle(arr);

    
}