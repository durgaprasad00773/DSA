#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3,3,2,3,1,3,2,2,1,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cand = 0;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(count ==0)
        {
            cand = arr[i];
            count++;
        }
        else{
            if(cand != arr[i])
            {
                count--;
            }
            else{
                count++;
            }
        }
    }
    cout << cand;
}