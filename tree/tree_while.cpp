#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
    int data;
    node* left, *right;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
int main()
{
    queue <node*> q;
    int n;
    cout << "Enter root : ";
    cin >> n;
    node* root = new node(n);
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        int first;
        cout << "Enter left : ";
        cin >> first;
        if(first != -1)
        {
            temp -> left = new node(first);
            q.push(temp -> left);
        }
        int second;
        cout << "Enter right : ";
        cin >> second;
        if(second!= -1)
        {
            temp -> right = new node(second);
            q.push(temp -> right);
        }
    }
    

}