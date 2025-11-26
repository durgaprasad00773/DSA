#include <iostream>
#include <vector>
using namespace std;
void subseq(vector<int> &arr, vector<vector<int>> &ans, int index, vector<int> &temp)
{
    if(index >= 3)
    {
        ans.push_back(temp);
        return;
    }
    //not included
    subseq(arr, ans, index+1, temp);
    //included
    temp.push_back(arr[index]);
    subseq(arr, ans, index+1, temp);
    temp.pop_back();

}
int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    subseq(arr, ans, 0, temp);
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout << j ;
        }
        cout << endl;
    }
}