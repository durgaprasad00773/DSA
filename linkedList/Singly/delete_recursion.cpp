#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

node* delete_node(node* curr, int x)
{
    if(x == 1)
    {
        node *temp = curr -> next;
        delete curr;
        return temp;
    }
    curr -> next = delete_node(curr->next, x-1);
    return curr;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    // array from which we are making the linked list

    int arr[] = {2, 6, 4, 9, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++)
    {
        if(head == NULL)
        {
            head = new node(arr[i]);
            tail = head;
        }
        else{
            tail -> next = new node(arr[i]);
            tail = tail -> next;
        }
    }
    //deleting node at a particular position using RECURSION

    int x = 4;
    head = delete_node(head, x);

    //printing the linkedList

    node* temp = head;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}