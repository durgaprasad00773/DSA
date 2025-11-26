#include <iostream>
#include <vector>
using namespace std;
int climb (int n, vector<int> &arr)
{
    if(n==0)
    return 1;

    if(n<0)
    return 0;

    if(arr[n] != -1)
    return arr[n];

    return arr[n]=climb(n-1, arr)+climb(n-2, arr);
}
int main()
{
    vector<int> arr(10001, -1);
    cout << climb(10000, arr);
}