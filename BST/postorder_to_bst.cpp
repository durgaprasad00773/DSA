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

//postorder array to BST

node* bst(vector<int> &arr, int &index, int lower, int upper)
{
    //base condition
    if(arr[index] >= upper || arr[index] < lower || index < 0)
    return NULL;

    node* temp = new node(arr[index]);
    index--;
    temp -> right = bst(arr, index, temp -> data, upper);
    temp -> left = bst(arr, index, lower, temp -> data);
    

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
    vector<int> arr = {1, 7, 5, 12, 10, 8};
    int index = arr.size()-1;
    node* root = bst(arr, index, INT_MIN, INT_MAX);
    inorder(root);
}