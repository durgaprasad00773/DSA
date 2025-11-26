#include <bits/stdc++.h>
using namespace std;
void inssort(vector<int> &arr)
{
    int n = arr.size();
    for(int i=1; i<n; i++)
    {
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    }
}
int main()
{
    vector<int> arr = {9, 4, 7, 1, 3, 0};
    inssort(arr);
    for(auto i : arr)
    {
        cout << i << "  ";
    }
}