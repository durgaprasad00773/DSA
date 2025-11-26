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
//maximum in each level
vector<int> maximum(node* root)
{
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            node* temp = q.front();
            q.pop();
            maxi = max(maxi, temp -> data);
            if(temp -> left)
            {
                q.push(temp -> left);
            }
            if(temp -> right)
            {
                q.push(temp -> right);
            }
        }
        ans.push_back(maxi);

    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, -1, -1, 5, -1, -1, -1, 20, -1, -1};
    int index = 0;
    node* root;
    root = tree(arr, index);
    vector <int> ans = maximum(root);
    for(auto i : ans)
    {
        cout << i << "  ";
    }
}