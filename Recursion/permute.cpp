#include <iostream>
#include <vector>
using namespace std;
void permute(vector<int> &arr, vector< vector<int> > &ans, vector<int> &temp, vector<int> &visited)
{
    //breaking
    if(temp.size() == arr.size())
    {
        ans.push_back(temp);
        return ;
    }
    //adding elements
    for(int i=0; i<arr.size(); i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            temp.push_back(arr[i]);
            permute(arr, ans, temp, visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}
int main()
{
    vector<int> arr = {1,2,3};
    vector< vector<int> > ans ;
    vector<int> temp;
    vector<int> visited (3,0);
    permute(arr, ans, temp, visited);
    for(auto i : ans)
    {
        for(auto j: i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
}