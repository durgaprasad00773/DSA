#include <iostream>
#include <vector>
using namespace std;
int ways(vector<int> &arr, int sum)
{
    //base condition
    if(sum == 0)
    {
        return 1;
    }
    if(sum < 0)
    {
        return 0;
    }
    
    int ans = 0;
    for(int i=0; i<arr.size(); i++)
    {
        ans += ways(arr, sum-arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1,5,6};
    int sum = 9;
    cout << ways(arr, sum);
}