#include <iostream>
#include <vector>
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
    int arr[] = {2, 2, 2, 3, 3, 4, 4};
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

    //removing duplicate node from a linked_list

    node *curr = head -> next;
    while(curr)
    {
        if(curr -> prev -> data == curr -> data)
        {
            node* temp = curr -> next;
            curr -> prev -> next = curr -> next;
            if(curr -> next != NULL)
            {
                curr -> next -> prev = curr -> prev;
            }
            delete curr;
            curr = temp;
        }
        else{
            curr = curr -> next;
        }
        
    }


    //displaying the doubly linked list
    
    node* temp = head;
    cout << "NULL";
    while (temp != NULL) {
        cout << " <- " << temp->data << " ->";
        temp = temp -> next;
    }
    cout << " NULL" << endl;

    

}