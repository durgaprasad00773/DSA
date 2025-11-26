#include <iostream>
#include <vector>
using namespace std;
class node
{
    public:
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
node* insert(node* root, int target)
{
    if(root == NULL)
    {
        node* temp = new node(target);
        return temp;
    }

    if(target < root -> data)
    {
        root -> left = insert(root -> left, target);
    }
    if(target >= root -> data)
    {
        root -> right = insert(root -> right, target);
    }

    return root;
}

//morris traversal

void inorder(node* root, vector<int> &ans)
{
    while(root)
    {
        //left doesn't exist
        if(root -> left == NULL)
        {
            ans.push_back(root -> data);
            root = root -> right;
        }
        //left exist
        else
        {
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
            //traversed
            else
            {
                curr -> right = NULL;
                ans.push_back(root -> data);
                root = root -> right;
            }
        }
    }
}

//ksum

void ksum(node* root, int &k, int &ans)
{
    if(k == 0 || root != NULL )
    return ;

    ksum(root -> left, k, ans);
    ans += root -> data;
    k--;
    ksum(root -> right, k, ans);
}
int main()
{
    vector<int> arr = {3, 6, 1, 8, 4, 0, 2};
    int n = arr.size();
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        root = insert(root, arr[i]);
    }
    int k = 3;
    int ans = 0;
    ksum(root, k, ans);
    cout << ans;

    
} 