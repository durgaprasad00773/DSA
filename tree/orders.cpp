#include <iostream>
#include <vector>
#include <queue>
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
void preorder(node* ptr)
{
    if(ptr == NULL)
    {
        return ;
    }
    cout << ptr -> data << "  ";
    //left
    preorder(ptr -> left);
    //right
    preorder(ptr -> right);
}
void inorder(node* ptr)
{
    if(ptr == NULL)
    {
        return ;
    }
    //left
    inorder(ptr -> left);
    cout << ptr -> data << "  ";
    inorder(ptr -> right);

}void postorder(node* ptr)
{
    if(ptr == NULL)
    {
        return ;
    }
    postorder(ptr -> left);
    postorder(ptr -> right);
    cout << ptr  -> data << "  ";
}
void levelorder(queue<node*> &q)
{   
    if(q.empty())
    return ;
    
    node* ptr = q.front();
    q.pop();

    if(ptr != NULL)
    {
        cout << ptr -> data << "  ";
        q.push(ptr -> left);
        q.push(ptr -> right);
    }

    levelorder(q);
}
int main()
{
    queue <node*> q;

    vector<int> arr = {1, 2, 3, 4, -1, -1, 5, -1, -1, -1, 20, -1, -1};
    int index = 0;
    node* root;
    root = tree(arr, index);
    q.push(root);

    levelorder(q);
}