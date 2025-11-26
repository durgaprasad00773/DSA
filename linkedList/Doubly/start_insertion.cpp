#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;
    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    node *head = NULL;
    //creating a doubly linked list from an array
    for(int i=0; i<n; i++)
    {
        if(head == NULL)
        {
            head = new node(arr[i]);
        }
        else{
            node* temp = new node(arr[i]);
            temp -> next = head;
            head -> prev = temp;
            head = temp;
        }
    }

    //displaying the doubly linked list

    // node* temp = head;
    // cout << "NULL";
    // while(temp)
    // {
    //     cout << " <- " << temp -> data << " -> ";
    //     temp = temp -> next;
    // }
    // cout << "NULL";
    node* temp = head;
    while(temp -> next)
    {
        temp = temp -> next;
    }
    cout << "NULL";
    while(temp)
    {
        cout << " <- " << temp -> data << " -> ";
        temp = temp -> prev;
    }
    cout << "NULL";

}