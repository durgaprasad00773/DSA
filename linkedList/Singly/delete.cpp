#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next ;
    node(int data)
    {
        this -> data = data;
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
    //deleting 1st node

    if(head != NULL)
    {
        node* t = head;
        head = head -> next;
        delete t;
    }

    //deleting last node
    
    if(head != NULL)
    {
        if(head -> next == NULL)
        {
            delete head;
            head = NULL;
        }
        else{
            node *curr = head;
            node *prev = NULL;
            while(curr -> next)
            {
                prev = curr;
                curr = curr -> next;
            }
            delete curr;
            prev -> next = NULL;
        }
    }

    // deleting at a particular node

    int x = 3;
    node *curr = head;
    node *prev = NULL;
    node *succ = head -> next;
    while(x-1)
    {
        prev = curr;
        curr = succ;
        succ = succ -> next;
        x--;
    }
    prev -> next  = succ;
    delete curr;
    

    //printing the linkedList

    node* temp = head;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}