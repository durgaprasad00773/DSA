#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int left , int right)
{
    int temp = right;
    int stand = left;
    int walk = left;
    for(int i=left; i<=right; i++)
    {
        if(arr[walk] <= arr[temp])
        {
            swap(arr[stand], arr[walk]);
            stand++;
        }
        walk++;
    }
    return stand-1;
}

int quick (vector<int> &arr, int left, int right, int k)
{
    if(left <= right)
    {
        int pivot = partition(arr, left, right);
        if(pivot == k-1)
        {
            return arr[pivot];
        }
        if(pivot < k-1)
        {
            return quick(arr, pivot+1, right, k);
        }

        return quick(arr, left, pivot-1, k);
    }
    return -1;
}
int main()
{
    vector<int> arr = {10, 20, 11, 70, 50, 40, 100, 5};
    int k = 1;
    cout << quick(arr, 0, arr.size()-1, k);

}