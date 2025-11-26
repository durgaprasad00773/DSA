#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

//left view

void left(node* root, vector<int> &ans, int level)
{
    if(root == NULL)
    {
        return ;
    }
    if(ans.size() == level)
    {
        ans.push_back(root -> data);
    }
    left(root -> left, ans, level+1);
    left(root -> right, ans, level+1);
}

//right view

void right(node* root, vector<int> &ans, int level)
{
    if(root == NULL)
    {
        return ;
    }
    if(ans.size() == level)
    {
        ans.push_back(root -> data);
    }
    right(root -> right, ans, level+1);
    right(root -> left, ans, level+1);
}

//top view

void top(node* root, vector<int> &ans, int x, int level, vector<int>& visited)
{
    if(root == NULL)
    return ;
    if(x == 0 && level == 0)
    {
        ans.push_back(root -> data);
    }
    if(x != 0)
    {
        ans.push_back(root -> data);
    }
    top(root -> left, ans, x-1, level+1, visited);
    top(root -> right, ans, x+1, level+1, visited);
}

int main()
{
    vector<int> arr = {1, 2, 4, -1, -1, 5, 7, -1, -1, 8, -1, 9, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;
    node *root = tree(arr, index);
    vector<int> ans;
    vector<int> visited(5, 0);
    top(root, ans, 0, 0, visited);
    for(auto i : ans)
    {
        cout << i << "  ";
    }
}