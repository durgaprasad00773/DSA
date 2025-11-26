#include <iostream>
using namespace std;
int binary(int arr[][4], int m, int n, int target)
{
    int start = 0;
    int end = m*n - 1;
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        int i=mid/n;
        int j = mid%n;
         if(arr[i][j] == target)
         {
            return 1;
         }
         else if(arr[i][j] < target)
         {
            start = mid + 1;
         }
         else{
            end = mid - 1;
         }
    }
    return 0;
}
int main()
{
    int arr[4][4] = {
        {1,4,5,7},
        {11,14,16,18},
        {19,21,24,26},
        {31,41,44,49}
    };
    int m=4;
    int n=4;
    int target = 1;
    cout << binary(arr,m ,n ,target);
}