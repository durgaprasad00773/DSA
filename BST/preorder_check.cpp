#include <iostream>
#include <vector>
#include <stack>
#include<math.h>
#include <climits>
using namespace std;
class node
{
    public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool check(vector<int> arr)
{
    int n = arr.size();
    stack <int> lower, upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    int left, right;
    for(int i=0; i<n; i++)
    {
        if(arr[i] < lower.top())
        {
            return 0;
        }
        while(arr[i] > upper.top())
        {
            lower.pop();
            upper.pop();
        }
        left = lower.top();
        right = upper.top();
        lower.pop();
        upper.pop();
        //right
        lower.push(arr[i]);
        upper.push(right);
        //left
        lower.push(left);
        upper.push(arr[i]);
    }
    return 1;
}
int main()
{
    vector<int> arr = {8, 5, 1, 7, 10, 12};
}