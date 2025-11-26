#include <iostream>
#include <vector>
#include <queue>
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
int getSize(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1+getSize(root -> left)+getSize(root -> right);
}

int sum(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return (root -> data + sum(root -> left) + sum(root -> right));
}

int leaves(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(!root -> left && !root -> right)
    {
        return 1;
    }
    return leaves(root -> left)+leaves(root -> right);
} 
int countNonLeafNodes(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(!root -> left && !root -> right)
    {
        return 0;
    }
    return  1+countNonLeafNodes(root -> left)+ countNonLeafNodes(root -> right);
}

int height(node* root)
{
    if(root == NULL)
    return 0;

    return 1+ max(height(root -> left) , height(root -> right));
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, -1, -1, 5, -1, -1, -1, 20, -1, -1};
    int index = 0;
    node* root;
    root = tree(arr, index);
    cout << height(root);
}