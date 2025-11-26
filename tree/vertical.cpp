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

//vertical traversal
void find(node* root, int &l, int &r, int x)
{
    if(root == NULL)
    return;
    l = min(l, x);
    r = max(r, x);
    find(root -> left, l, r, x-1);
    find(root -> right, l, r, x+1);
}
vector<int> vertical(node* root)
{
    int l =0, r=0;
    find(root, l, r, 0);
    vector< vector<int>> positive(r+1);
    vector<vector<int>> negative(-l+1);
    queue<node*> q;
    queue<int> index;
    q.push(root);
    index.push(0);
    while(!q.empty())
    {
        node* temp = q.front();
        int pos = index.front();
        q.pop();
        index.pop();
        if(pos < 0)
        {
            negative[-pos].push_back(temp -> data);
        }
        if(pos >= 0)
        {
            positive[pos].push_back(temp -> data);
        }
        if(temp -> left)
        {
            q.push(temp -> left);
            index.push(pos-1);
        }
        if(temp -> right)
        {
            q.push(temp -> right);
            index.push(pos+1);
        }
    }
    vector<int> ans;
    for(int i=negative.size()-1; i>0; i--)
    {
        for(int j=0; j<negative[i].size();j++)
        {
            ans.push_back(negative[i][j]);
        }
    }
    for(int i=0; i<positive.size(); i++)
    {
        for(int j=0; j<positive[i].size(); j++)
        {
            ans.push_back(positive[i][j]);
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = {1, 2, 4, 9, -1, -1, 6, -1, -1, 5, -1, -1, 3, -1, 7, -1, -1};
    int index = 0;
    node* root = tree(arr, index);
    vector<int> ans = vertical(root);
    for(auto i : ans)
    {
        cout << i << "  "; 
    }
}