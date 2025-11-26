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
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int value;
        cout << "Enter the data : ";
        cin >> value;
        if(head == NULL)
        {
            head = new node(value);
            tail = head;
        }
        else{
            tail -> next = new node(value);
            tail = tail -> next;
        }
    }
    //Adding a value 999 at index 2;
    node* temp = head;
    for(int i=0; i<2-1; i++)
    {
        temp = temp -> next;
    }
    node *ptr = new node(999);
    ptr -> next = temp -> next;
    temp -> next = ptr;


    //printing the linkedList

    temp = head;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}