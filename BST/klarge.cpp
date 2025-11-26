#include <iostream>
#include <vector>
#include<math.h>
#include <climits>
using namespace std;
class node
{
    public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
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
    else{
        root -> right = insert(root -> right, target);
    }

    return root;
}

//kth - largest

int klarge(node* root, int &k)
{
    if(root == NULL)
    return 0;

    return klarge(root -> right, k);

    k--;
    if(k==0)
    {
        return root -> data;
    }
    else{
        return 0;
    }
    return klarge(root -> left, k);



}

int main()
{
    vector<int> arr = {20, 10, 30, 2, 14, 25, 35};
    int n = arr.size();
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        root = insert(root, arr[i]);
    }
    int k=3;
    cout << klarge(root, k);

}