#include <iostream>
using namespace std;
int linear(int arr[], int n, int target, int index)
{
    if(index == n)
    {
        return -1;
    }
    if(arr[index] == target)
    {
        return index;
    }
    return linear(arr, n, target , index+1);
}
int main()
{
    int arr[] = {2,8,-1,5,22, 76, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << linear(arr, n, 22, 0);
}