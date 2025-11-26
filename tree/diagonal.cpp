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

//diagonal traversal
void find(node* root, int &l, int x)
{
    if(root == NULL)
    return ;
    l = min(l, x);
    find(root -> left, l, x-1);
}
void fill(vector<vector<int>> &arr, node*root, int l)
{
    if(root == NULL)
    return ;
    arr[l].push_back(root -> data);
    fill(arr, root -> left, l+1);
    fill(arr, root -> right, l);
}
vector<int> diagonal(node* root)
{
    int l=0;
    find(root, l, 0);    
    vector< vector<int> > arr(-l+1);
    fill(arr, root, 0);
    vector<int> ans;
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            ans.push_back(arr[i][j]);
        }
    }
    return ans;

}
int main()
{
    vector<int> arr = {1, 2, 4, 9, -1, -1, 6, -1, -1, 5, -1, -1, 3, -1, 7, -1, -1};
    int index = 0;
    node* root = tree(arr, index);
    vector<int> ans = diagonal(root);
    for(auto i: ans)
    {
        cout << i << "  ";
    }
}