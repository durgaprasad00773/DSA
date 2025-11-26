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
    //displaying the doubly linked list
    
    node* temp = tail;
    cout << "NULL";
    while (temp != NULL) {
        cout << " <- " << temp->data << " ->";
        temp = temp -> prev;
    }
    cout << " NULL" << endl;


}