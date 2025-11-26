#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    if(i >= n)
    return ;

    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    if(leftChild < n && arr[leftChild] < arr[largest])
    {
        largest = leftChild;
    }
    if(rightChild < n && arr[rightChild] < arr[largest])
    {
        largest = rightChild;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);

    }
}
int main()
{
    int arr[] = {3, 6, 1, 9, 4, 2, 0, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);


    for(int i=n/2 -1 ; i>=0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i=n-1; i>0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }

}