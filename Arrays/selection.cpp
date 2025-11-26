#include <iostream>
using namespace std;
void selection (int arr[] , int n)
{
    for(int i=0; i<n; i++)
    {
        int index = i;
        for(int j=i; j<n; j++)
        {
            if(arr[j] < arr[index])
            {
                index = j;
            }
        }
        swap(arr[i] , arr[index]);
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }
}
int main()
{
    int arr[] = {2,-1,4,2,6,4,8,4,8,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
}