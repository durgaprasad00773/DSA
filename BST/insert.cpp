#include <iostream>
#include <vector>
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
node* insert(node* root, int target)
{
    if(root == NULL)
    {
        node* temp = new node(target);
        return temp;
    }
    if(target < root -> data)
    {
        root -> left = insert(root -> left, target);
    }
    else{
        root -> right = insert(root -> right, target);
    }

    return root;
}
void inorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root -> left);

    cout << root -> data << "  ";
    inorder(root -> right);
}

bool search(node* root, int target)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root -> data == target)
    {
        return 1;
    }
    else if(target < root -> data)
    {
        return search(root -> left, target);
    }
    else
    return search(root -> right, target);
}
int main()
{
    vector<int> arr = {8, 4, 3, 6, 11, 13};
    int n = arr.size();
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        root = insert(root, arr[i]);
    }
    cout << search(root, 99);


}