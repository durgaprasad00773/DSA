#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr, int index)
{
    if(index >= arr.size())
    return ;

    for(int i=index; i>0; i--)
    {
        if(arr[i] < arr[i-1])
        {
            swap(arr[i], arr[i-1]);
        }
        else
        {
            break;
        }
    }

    insertionSort(arr, index+1);
}
int main()
{
    vector<int> arr = {3, 1, 7, 5, 9, 2, 0};
    int n = arr.size();

    insertionSort(arr, 1);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }
}