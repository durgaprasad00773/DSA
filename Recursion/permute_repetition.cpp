#include <iostream>
#include <vector>
using namespace std;
void permute(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    //base condition
    if(index >= arr.size())
    {
        ans.push_back(arr);
        return ;
    }
    vector<bool> visited(21,0);
    for(int i=index; i<arr.size(); i++)
    {
        if(visited[arr[i] + 10] == 0)
        {
            swap(arr[i], arr[index]);
            permute(arr, ans, index+1);
            swap(arr[i], arr[index]);
            visited[arr[i] + 10] = 1;
        }
        
    }
}
int main()
{
    vector<int> arr = {1,1,2};
    vector<vector<int>> ans ;
    int index = 0;
    permute(arr, ans, index);
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}