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

//top view
void find(node* root, int x, int &l, int &r)
{
    if(root == NULL)
    return ;
    l = min(l, x);
    r = max(r, x);
    find(root -> left, x-1, l, r);
    find(root -> right, x+1, l, r);
}
vector<int> top(node* root)
{
    int l =0, r=0;
    find(root, 0, l,r);
    vector<int> ans(r-l+1, 0);
    vector<int> visited(r-l+1, 0);
    queue<node*> q;
    queue<int>  index;
    q.push(root);
    index.push(-l);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();
        if(visited[pos] == 0)
        {
            visited[pos] = 1;
            ans[pos] = temp -> data;
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
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, -1, -1, 5, 7, -1, -1, 8, -1, 9, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;
    node *root = tree(arr, index);
    vector<int> ans = top(root);
    for(auto i : ans)
    {
        cout << i << "  ";
    }
}