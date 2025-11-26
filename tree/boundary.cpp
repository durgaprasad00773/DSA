#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
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

//boundary traversal
void left(node* root, vector<int> &ans)
{
    if(!root || (!root -> left && !root -> right))
    return ;
    ans.push_back(root -> data);
    if(root -> left)
    left(root -> left, ans);
    else
    left(root -> right, ans);
}
void leaf(node* root, vector<int> &ans)
{
    if(root == NULL)
    return ;
    if(root->left == NULL && root -> right == NULL)
    {
        ans.push_back(root -> data);
    }
    leaf(root -> left, ans);
    leaf(root -> right, ans);
}
void right(node* root, vector<int>& ans)
{
    if(!root || (!root -> right && !root -> left))
    return ;

    if(root -> right)
    {
        right(root -> right, ans);
    }
    else
    {
        right(root -> left, ans);
    }
    ans.push_back(root -> data);
}
vector<int> boundary(node* root)
{
    vector<int> ans;
    ans.push_back(root -> data);
    left(root -> left, ans);
    leaf(root, ans);
    right(root -> right, ans);

    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 9, -1, -1, 6, -1, -1, 5, -1, -1, 3, -1, 7, -1, -1};
    int index = 0;
    node* root = tree(arr, index);
    vector<int> ans = boundary(root);
    for(auto i: ans)
    {
        cout << i << "  ";
    }
}