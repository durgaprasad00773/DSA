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
int height(node* root, bool &valid)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = height(root -> left, valid);
    int r = height(root -> right, valid);
    if(abs(l-r) > 1)
    {
        valid = 0;
    }
    return 1+max(l, r);
}
bool check(node* root)
{
    bool valid = 1;
    height(root, valid);
    return valid;
}
int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, -1, 4, -1, 5, -1, -1};
    int index = 0;
    node *root = tree(arr, index);
    cout << check(root);

}