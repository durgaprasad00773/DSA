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
void preorder(node* root)
{
    stack<node*> st;
    st.push(root);
    while(!st.empty())
    {
        node* temp = st.top();
        st.pop();
        cout << temp -> data << "  ";
        if(temp -> right)
        {
            st.push(temp -> right);
        }
        if(temp -> left)
        {
            st.push(temp -> left);
        }
    }
}
vector<int> postorder(node* root)
{
    vector<int> ans;
    stack<node*> st;
    st.push(root);
    while(!st.empty())
    {
        node* temp = st.top();
        st.pop();
        ans.push_back(temp -> data);
        if(temp -> left)
        {
            st.push(temp -> left);
        }
        if(temp -> right)
        {
            st.push(temp -> right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//inorder
vector<int> inorder(node* root)
{
    stack<node*> st;
    stack<bool> visited;
    st.push(root);
    visited.push(0);
    vector<int> ans;
    while(!st.empty())
    {
        node* temp = st.top();
        st.pop();
        bool flag = visited.top() ;
        visited.pop();
        if(flag == 0)
        {
            if(temp -> right)
            {
                st.push(temp -> right);
                visited.push(0);
            }
            st.push(temp);
            visited.push(1);
            if(temp -> left)
            {
                st.push(temp -> left);
                visited.push(0);
            }
        }
        else
        {
            ans.push_back(temp -> data);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 9, -1, -1, -1,5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int index = 0;
    node* root = tree(arr, index);
    vector<int> ans = inorder(root);
    for(auto i : ans)
    {
        cout << i << "  ";
    }
}