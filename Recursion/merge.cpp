#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int start, int mid, int end);
void mergesort(int arr[], int start, int end);
int main()
{
    int arr[] = {7,2,5,4,9,3};
    mergesort(arr, 0, 5);
    for(int i=0; i<6; i++)
    {
        cout << arr[i] << "  ";
    }
}
void mergesort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    // left
    mergesort(arr, start, mid);
    // right
    mergesort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
void merge(int arr[], int start, int mid, int end)
{
    int left = start;
    int right = mid + 1;
    int index = 0;
    vector<int> temp(end - start + 1);
    while (left <= mid && right <= end)
    {
        if (arr[left] < arr[right])
        {
            temp[index] = arr[left];
            left++;
            index++;
        }
        else
        {
            temp[index] = arr[right];
            right++;
            index++;
        }
    }
    while (left <= mid)
    {
        temp[index] = arr[left];
        left++;
        index++;
    }
    while(right <= end)
    {
        temp[index] = arr[right];
        right++;
        index++;
    }

    //changing elements from temp to arr
    index = 0;
    while(start <= end)
    {
        arr[start] = temp[index];
        index++;
        start++;
    }
}