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
    int n;
    cin >> n;
    node *head = NULL;
    int value;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the node data : ";
        cin >> value;
        if (head == NULL)
        {
            head = new node(value);
        }
        else{
            
            node *temp;
            temp = new node(value);
            temp -> next = head;
            head = temp;
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