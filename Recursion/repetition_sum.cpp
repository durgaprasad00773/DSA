#include <iostream>
#include <vector>
using namespace std;
int repetition_sum(vector<int> arr, int target, int index, int n)
{
    //breaking
    if(target == 0)
    {
        return 1;
    }
    if(target < 0 || index >= n)
    {
        return 0;
    }

    return repetition_sum(arr, target, index+1, n) + repetition_sum(arr, target-arr[index], index, n);
}
int main()
{
    vector<int> arr = {2,3,4};
    int target = 6;
    int index = 0;
    int n = arr.size();
    cout << repetition_sum(arr, target, index, n);
}