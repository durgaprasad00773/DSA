#include <iostream>
#include <vector>
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

//preorder array to BST

node* bst(vector<int> &arr, int &index, int lower, int upper)
{
    //base condition
    if(arr[index] >= upper || arr[index] < lower || index >= arr.size())
    return NULL;

    node* temp = new node(arr[index]);
    index++;
    temp -> left = bst(arr, index, lower, temp -> data);
    temp -> right = bst(arr, index, temp -> data, upper);

    return temp;

}

void inorder(node* root)
{
    if(root == NULL)
    return ;

    
    inorder(root -> left);
    cout << root -> data << "  ";
    inorder(root -> right);
}

int main()
{
    vector<int> arr = {8, 5, 7, 7, 10, 12};
    int index = 0;
    node* root = bst(arr, index, INT_MIN, INT_MAX);
    inorder(root);
}