#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3,3,2,3,1,3,2,2,1,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
    {
        arr[i]--;
    }
    for(int i=0; i<n; i++)
    {
        arr[arr[i]%n] += n;
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]/7 > n/2)
        {
            cout << i+1 << "  ";
        }
    }
}