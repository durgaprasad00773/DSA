#include <iostream>
using namespace std;
void quicksort(int arr[], int start, int end);
int partition(int arr[] ,int start, int end);
int main()
{
    int arr[] = {7,2,5,4,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
     }
}
void quicksort(int arr[], int start, int end){
    if(start >= end)
    {
        return;
    }
    int pivot = partition(arr, start, end);
    //left
    quicksort(arr, start, pivot-1);
    //right
    quicksort(arr, pivot+1, end);
}
int partition(int arr[] ,int start, int end)
{
    int temp = arr[end];
    int stand = start;
    int walk = start;
    while(walk <= end)
    {
        if(arr[walk] <= temp)
        {
            swap(arr[walk], arr[stand]);
            stand++;
        }
        walk++;
    }
    return stand-1;
}