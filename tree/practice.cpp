#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
    int data;
    node* left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
node* tree()
{
    int x;
    cout << "Enter node value : ";
    cin >> x;
    if(x == -1)
    return NULL;

    node* temp = new node(x);
    temp -> left = tree();
    temp -> right = tree();

    return temp;
}
void inorder(node * root)
{
    if(root == NULL)
    return ;

    inorder(root -> left);
    cout << root -> data << "  ";
    inorder(root -> right);
}
void level(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        cout << temp -> data << "  ";
        if(temp -> left)
        q.push(temp -> left);
        if(temp -> right)
        q.push(temp -> right);
        
    }
}
int main()
{
    node* root = NULL;
    root = tree();

    level(root);
}