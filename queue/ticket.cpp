#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int timeRequiredToBuy(vector<int>& arr, int k) {
    queue <int> q;
    for(int i=0; i<arr.size(); i++)
    {
        q.push(i);
    }
    int time = 0;
    while (arr[k] != 0)
    {
        arr[q.front()]--;
        time++;
        if(arr[q.front()] != 0)
        {
            q.push(q.front());
        }
        q.pop();

    }
    return time;
    

}
int main()
{
    vector<int> arr = {2, 6, 4, 3, 7};
    int k = 2;
    cout << timeRequiredToBuy(arr, k);
}