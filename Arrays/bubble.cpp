#include <iostream>
using namespace std;
void bubble(int arr[] ,int n)
{
    for(int i=n-1; i>0; i--)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }
}
int main()
{
    int arr[] = { 2,-1,4,2,6,4,8,4,8,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble(arr,n);
}