#include <iostream>
#include <vector>
#include <queue>
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
vector< vector<int> > level(node* root)
{
    queue<node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty())
    {
        vector<int> mem;
        int n = q.size();
        for(int i=0; i<n; i++)
        {
            node* temp = q.front();
            q.pop();
            mem.push_back(temp -> data);
            if(temp -> left)
            {
                q.push(temp -> left);
            }
            if(temp -> right)
            {
                q.push(temp -> right);
            }
        }
        ans.push_back(mem);

    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, -1, -1};
    int index = 0;
    node *root = tree(arr, index);
    vector<vector<int>> ans = level(root);
    for(auto i: ans)
    {
        for (auto j: i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
}