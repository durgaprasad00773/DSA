#include <iostream>
using namespace std;

void heapify(int arr[], int n, int index)
{
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}
void maxHeap(int arr[], int n)
{
    for(int i=n/2-1 ; i>= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void heapsort(int arr[], int n)
{
    maxHeap(arr, n);
    int i=n-1;
    while(i>0)
    {
        swap(arr[i], arr[0]);
        i--;
        heapify(arr, i, 0);
    }

}
int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70, 34, 0, -34, -98};
    int  n = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr, n);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }
}