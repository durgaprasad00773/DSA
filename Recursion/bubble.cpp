#include <iostream>
#include <vector>
using namespace std;
void bubble(int arr[] , int r, int c)
{
    if(r==0)
    {
        return;
    }
    if(c < r)
    {
        if(arr[c] > arr[c+1])
        {
            swap(arr[c] , arr[c+1]);
        }
        bubble(arr,r,c+1);
    }
    else{
        bubble(arr,r-1,0);
    }
}
int main()
{
    int arr[] = {4,2,1,3,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble(arr, 6,0);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  " ; 
    }
}