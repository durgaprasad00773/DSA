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
    node *temp = head;

    //deleting without head pointer
    node *curr = head -> next -> next ; //4 int this case
    head = NULL;
    node *ptr = curr -> next;
    curr -> data = ptr -> data;
    curr -> next = ptr -> next;
    delete ptr;
    

    //printing the linkedList

    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}