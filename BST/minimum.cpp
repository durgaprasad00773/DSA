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

//minimum distance

void minimum(node* root, int &mini, int &prev)
{
    if(root == NULL)
    return ;

    minimum(root -> left, mini, prev);
    mini = min(mini, abs(root -> data- prev));
    prev = root -> data;

    minimum(root -> right, mini, prev);
}

int main()
{
    vector<int> arr = {2, 10, 14, 20, 25, 30, 35};
    int n = arr.size();
    node* root = NULL;
    for(int i=0; i<n; i++)
    {
        root = insert(root, arr[i]);
    }
    int prev = INT_MIN;
    int mini = INT_MAX;
    minimum(root, mini, prev);
    cout << mini;


}