#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *left, *right;
    int height;

    node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(node* root)
{
    if(root == NULL)
    return 0;

    return root -> height;
}

int checkBalance(node* root)
{
    return getHeight(root -> left)-getHeight(root -> right);
}

//Right Rotation

node* rightRotation(node* root)
{
    node* child = root -> left;
    node* childRight = child -> right;
    child -> right = root ;
    root -> left = childRight;

    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));
    child -> height = 1 + max(getHeight(child -> left), getHeight(child -> right));

    return child;
}

//Left Rotation

node* leftRotation(node* root)
{
    node* child = root -> right;
    node *childLeft = child -> left;
    child -> left = root;
    root -> right = childLeft;

    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));
    child -> height = 1 + max(getHeight(child -> left), getHeight(child -> right));

    return child;

}

node* insert(node* root, int key)
{
    //Doesn't exist
    if(root == NULL)
    return new node(key);

    //exist

    if(key < root -> data)
    {
        root -> left = insert(root -> left, key);
    }

    else if(key > root -> data)
    {
        root -> right = insert(root -> right, key);
    }

    else
    {
        return root;
    }


    //updating height
    root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));



    //check balancing
    int balance = checkBalance(root);
    //LL
    if(balance > 1 && root -> left -> data > key)
    {
        return rightRotation(root);
    }

    //LR

    else if(balance > 1 && root -> left -> data < key)
    {
        root -> left = leftRotation(root -> left);
        return rightRotation(root);
    }

    //RR
    else if(balance < -1 && root -> right -> data < key)
    {
        return leftRotation(root);
    }

    //RL
    else if(balance < -1 && root -> right -> data > key)
    {
        root -> right = rightRotation(root -> right);
        return leftRotation(root);
    }

    else{
        return root;
    }



}

void preorder(node* root)
{
    if(!root)
    return ;

    cout << root -> data << "  ";
    preorder(root -> left);
    preorder(root -> right);
}

int main()
{
    node* root = NULL;
    root = insert(root, 11);
    root = insert(root, 22);
    root = insert(root, 37);
    root = insert(root, 48);
    root = insert(root, 55);
    root = insert(root, 19);
    root = insert(root, 28);
    root = insert(root, 31);
    root = insert(root, 40);
    root = insert(root, 77);

    preorder(root);
}