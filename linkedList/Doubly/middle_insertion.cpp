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
    node *tail = NULL;
    for(int i=0; i<n; i++)
    {
        if(head == NULL)
        {
            head = new node(arr[i]);
            tail = head;
        }
        else{
            node *temp = new node(arr[i]);
            tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
        }
    }

    //inserting the node at any desired index

    int pos = 3;
    pos--;
    node* curr = head;
    while(--pos)
    {
        curr = curr -> next;
    }
    node *ptr = new node(999);
    ptr -> next = curr -> next;
    ptr -> prev = curr;
    curr -> next = ptr;
    ptr -> next -> prev = ptr;
    

    //displaying the doubly linked list
    
    node* temp = head;
    cout << "NULL";
    while (temp != NULL) {
        cout << " <- " << temp->data << " ->";
        temp = temp -> next;
    }
    cout << " NULL" << endl;


}