#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr, int n)
{
    //basecase
    if(n == 1)
    return ;

    for(int i=0; i<n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, n-1);
}
int main()
{
    vector<int> arr = {2, 8, 4, 0, 1, 7, 4};
    int n = arr.size();

    bubbleSort(arr, n);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }
}