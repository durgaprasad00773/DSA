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
void mirror(node *root)
{
    if(root == NULL)
    {
        return ;
    }
    node* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    mirror(root -> left);
    mirror(root -> right);
}
int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, -1, -1};
    int index = 0;
    node *root = tree(arr, index);
}