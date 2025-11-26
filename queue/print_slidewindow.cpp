#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void display(queue<int> q, int k)
{
    while(!q.empty()) //pass by value, so no change will be occured in the original QUEUE;
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
void slide(vector<int> arr, int k)
{
    int n = arr.size();
    queue <int> q;
    for(int i=0; i<k-1; i++)
    {
        q.push(arr[i]);
    }
    for(int i=k-1; i<n; i++)
    {
        q.push(arr[i]);
        display(q, k);
        q.pop();
    }
}
int main()
{
    vector<int> arr = {2, 5, 6, 3, 5, 8, 7, 8};
    int k = 3;
    slide(arr, k);
}