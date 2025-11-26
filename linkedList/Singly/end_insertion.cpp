#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
int main()
{
    node *head;
    node *ptr;
    head = NULL;
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
            ptr = head;
        }
        else{
            while (ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new node(value);
            ptr = ptr -> next;
        }
    }
    node *temp;
    temp = head;
    while(temp)
    {
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "Null";
    
}