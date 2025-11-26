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

vector<int> spiral(node *root)
{
    stack<node*> rtl;
    stack<node*> ltr;
    rtl.push(root);
    vector<int> ans;
    while(rtl.empty() == 0 || ltr.empty() == 0)
    {
       if(!rtl.empty())
       {
            while(!rtl.empty())
            {
                node *temp = rtl.top();
                rtl.pop();
                ans.push_back(temp -> data);
                if(temp -> right)
                {
                    ltr.push(temp -> right);
                }
                if(temp -> left)
                {
                    ltr.push(temp -> left);
                }
            }
       }
       else
       {
        while(!ltr.empty())
        {
            node *temp = ltr.top();
            ltr.pop();
            ans.push_back(temp -> data);
            if(temp -> left)
            {
                rtl.push(temp -> left);
            }
            if(temp -> right)
            {
                rtl.push(temp -> right);
            }
        }
       }
    }
    return ans;

}

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, -1, 4, -1, 5, -1, -1};
    int index = 0;
    node *root = tree(arr, index);
    vector<int> ans = spiral(root);
    for( auto i : ans)
    {
        cout << i << "  ";
    }

}