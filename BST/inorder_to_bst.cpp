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

//inorder array to BST

node* bst(vector<int> arr, int start, int end, vector<int>& ans)
{
    if(start > end)
    {
        return NULL;
    }
    int mid = start + (end - start)/2;
    node* temp = new node(arr[mid]);
    ans.push_back(arr[mid]);
    temp -> left = bst(arr, start, mid-1, ans);
    temp -> right = bst(arr, mid+1, end, ans);
    return temp;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();
    vector<int> ans;
    node* root = bst(arr, 0, arr.size()-1, ans);
    for(auto i : ans)
    {
        cout << i << "  ";
    }

}