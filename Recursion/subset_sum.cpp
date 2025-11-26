#include <iostream>
#include <vector>
using namespace std;
void subset_sum(vector<int> arr, vector<int> &ans, int temp, int index)
{
    if(index>=arr.size())
    {
        ans.push_back(temp);
        return;
    }
    //not included
    subset_sum(arr,ans, temp, index+1);
    //included
    temp = temp+arr[index];
    subset_sum(arr, ans, temp, index+1);
}
int main()
{
    vector<int> arr = {3,4,5};
    vector<int> ans;
    int temp=0;
    int index = 0;
    subset_sum(arr, ans, temp, index);
    for(auto i : ans)
    {
        cout << i << "  ";
    }
}