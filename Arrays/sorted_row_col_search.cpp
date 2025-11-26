#include <iostream>
using namespace std;
int search(int arr[][5], int target, int m, int n)
{
    int i=0;
    int j=4;
    while(j>=0 & i<=4)
    {
        int x = arr[i][j];
        if(x == target)
        {
            return 1;
        }
        else if (x < target)
        {
            i++;
        }
        else{
            j--;
        }
        
    }
    return 0;
}
int main()
{
    int arr[5][5] = {
        {4,8,15,25,60},
        {18,22,26,42,80},
        {36,40,45,68,104},
        {48,50,72,83,130},
        {70,99,114,128,170}
    };
    int m = 5;
    int n = 5;
    int target =10;
    cout << search(arr, target, m ,n);
}