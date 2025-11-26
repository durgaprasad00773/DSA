#include <iostream>
#include <vector>
using namespace std;
int winner(vector<int> &arr, int person_left, int index, int k, int n)
{
    //base condition
    if(person_left == 1)
    {
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == 0)
            {
                return i;
            }
        }
    }
    
    int kill = (k-1)%person_left;
    while(kill--)
    {
        index = (index+1)%n;
        while(arr[index] == 1)
        {
            index = (index+1)%n;
        }
    }
    arr[index] = 1;
    while(arr[index]==1)
    {
        index = (index+1)%n;
    }
    return winner(arr, person_left-1, index, k, n);
}
int main()
{
    vector<int> arr = {0, 0, 0, 0, 0, 0,0};
    int k = 4;
    int n = arr.size();
    int person_left = n;
    int index = 0;
    cout << winner(arr, person_left, index, k, n);
}