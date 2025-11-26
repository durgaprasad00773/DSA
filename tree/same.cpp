#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class node
{
    public:
    int data;
    node* left , *right;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
node* tree(vector<int> & arr, int & index)
{
    if(index >= arr.size() || arr[index] == -1)
    {
        index++;
        return NULL;
    }
    node* temp = new node(arr[index]);
    index++;
    //left 
    temp -> left = tree(arr, index);
    //right
    temp -> right = tree(arr, index);
    return temp;
}

bool same(node*r1, node* r2)
{
    if(!r1 && !r2)
    {
        return 1;
    }
    if((!r1 && r2 ) || (!r2 && r1))
    {
        return 0;
    }
    if(r1 -> data != r2 -> data)
    {
        return 0;
    }
    return same(r1 -> left, r2 -> left) && same(r1 -> right, r2 -> right);
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, -1, -1, 5, -1, -1, -1, 20, -1, -1};
    vector<int> arr2 = {1, 2, 3, 4, -1, -1, 5, -1, -1, -1, 2, -1, -1};
    int index1 = 0;
    int index2 = 0;
    node* r1, *r2;
    r1 = tree(arr1, index1);
    r2 = tree(arr2, index2);
    cout << same(r1, r2);
}