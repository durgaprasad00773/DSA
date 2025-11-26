#include <iostream>
#include <vector>
using namespace std;
int perfect_sum(vector<int> arr,int target, int index,int n)
{
    if(index == n)
    {
        if(target == 0)
        {
            return 1;
        }
        else{
            return 0;
        }
    }

    return perfect_sum(arr, target, index+1, n)+ perfect_sum(arr, target-arr[index], index+1, n);
}
int main()
{
    vector<int> arr = {0,1};
    int target = 1;
    int index = 0;
    int sum = 0;
    cout << perfect_sum(arr,target, index,arr.size());
}