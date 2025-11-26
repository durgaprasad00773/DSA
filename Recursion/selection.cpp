#include <iostream>
using namespace std;
void selection(int arr[], int max, int r, int c)
{
    if(r==0)
    {
        return;
    }
    if(c<r)
    {
        if(arr[c] > arr[max])
        {
            selection(arr,c,r,c+1);
        }
        else{
             selection(arr,max,r,c+1);
        }
    }
    else{
        swap(arr[max], arr[r-1]);
    }
    selection(arr,0,r-1,0);
}
int main()
{
    int arr[]  = {2,1,9,4,8,3,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection(arr, 0, n, 0);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }
}