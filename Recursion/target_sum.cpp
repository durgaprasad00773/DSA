#include <iostream>
#include <vector>
using namespace std;
bool target_sum(vector<int> arr, int target, int n, int index)
{
    if (target == 0)
    {
        return true;
    }
    if(index >= n || target < 0)
    {
        return false;
    }
    return target_sum(arr, target, n, index+1) || target_sum(arr, target-arr[index], n, index+1);
}
int main()
{
    vector<int> arr = {3,6,4,5};
    int target = 11;
    int n = arr.size();
    int index = 0;
    cout << target_sum(arr, target, n, index);
}