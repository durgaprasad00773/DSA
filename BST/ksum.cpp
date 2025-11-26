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

//k smallest elements sum
void total(node* root, int &sum, int &k)
{
    if(root == NULL)
    return ;

    total(root -> left, sum, k);
    k--;
    if(k>=0)
    {
        sum = sum+root -> data;
    }
    else{
        return;
    }
    total(root -> right, sum, k);
    
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
    int sum = 0;
    int k = 3;

    total(root, sum, k);
    cout << sum;


}