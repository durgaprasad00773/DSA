#include <iostream>
using namespace std;
int main()
{
    int arr[] = {4,3,2,1,2,7,6};
    int n = 7;
    for(int i=0; i<n; i++)
    {
        arr[i]--;
    }
    for(int i=0; i<n; i++)
    {
        arr[arr[i]%7] = arr[arr[i]%7] +7;
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]/7 == 0)
        {
            cout << "missing : " << i+1;
        }
        if(arr[i]/7 > 1)
        {
            cout << "repetition : " << i+1; 
        }
    }
    
}