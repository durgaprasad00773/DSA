#include <iostream>
#include <vector>
using namespace std;
vector <int> linear(vector<int> arr, int target, int index, vector<int> ans)
{
    if(index == arr.size())
    {
        return ans;
    }
    if(arr[index] == target)
    {
        ans.push_back(index);
    }
    return linear(arr, target, index+1, ans);
}
int main()
{
    vector <int> arr = {2,0,6,0,-1,0,4,0,2,0,4,7,0,0};
    vector <int> vec ;
    vector<int> ans;
    vec = linear(arr, 0, 0 , ans);
    for(auto i : vec)
    {
        cout << i << "  ";
    }
}