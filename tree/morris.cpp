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

//morris traversal

vector<int> inorder(node* root)
{
    vector<int> ans;
    //LNR
    while(root)
    {
        //left doesnt exist
        if(!root -> left)
        {
            ans.push_back(root -> data);
            root = root -> right;
        }
        else{
            node* curr = root -> left;
            while(curr -> right != NULL && curr -> right != root)
            {
                curr = curr -> right;
            }
            //not traversed
            if(curr -> right == NULL)
            {
                curr -> right = root;
                root = root -> left;
            }
            else
            {
                curr -> right == NULL;
                ans.push_back(root -> data);
                root = root -> right;
            }
        }

    }
    return ans;

}
vector<int> preorder(node* root)
{
    vector<int> ans;
    while(root)
    {
        if(!root -> left)
        {
            ans.push_back(root -> data);
            root = root -> right;
        }
        else
        {
            node* curr = root -> left;
            while(curr -> right != NULL && curr -> right != root)
            {
                curr = curr -> right;
            }
            //not tarversed
            if(curr -> right == NULL)
            {
                ans.push_back(root -> data);
                curr -> right = root;
                root = root -> left;
            }
            //travrsed
            else{
                curr -> right = NULL;
                root = root -> right;
            }
        }
    }
    return ans;
}
vector<int> postorder(node* root)
{
    vector<int> ans;
    while(root)
    {
        if(root -> right == NULL)
        {
            ans.push_back(root -> data);
            root = root -> left;
        }
        else
        {
            node* curr = root -> right;
            while(curr -> left != NULL && curr -> left != root)
            {
                curr = curr -> left;
            }
            if(curr -> left == NULL)
            {
                curr -> left = root;
                ans.push_back(root -> data);
                root = root -> right;
            }
            else
            {
                curr -> left = NULL;
                root = root -> left;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 7, -1, -1, 8, -1, -1, 5 , -1, 9, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;
    node* root = tree(arr, index);
    vector<int> ans = postorder(root);
    for (auto i : ans)
    {
        cout << i << "  ";
    }
}