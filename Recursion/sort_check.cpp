#include <iostream>
using namespace std;
bool check(int arr[], int i, int n);
int main()
{
    int arr[] = {1,3,4,6,9,12,22};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << check(arr, 0, n);
}
bool check(int arr[], int i, int n)
{
    if(i+1 == n)
    {
        return 1;
    }
    if(arr[i] > arr[i+1])
    {
        return 0;
    }
    check(arr, i+1 , n);
}