#include <iostream>
#include <vector>
using namespace std;
class node
{
    public:
    int data;
    node *next ;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
int main()
{
    node* head = new node(10);
    head -> next = new node(20);
    head -> next -> next = new node(30);
    head -> next -> next -> next = new node(40);
    head -> next -> next -> next -> next = new node(50);

    //reverseing the nodes

    node *pre = head;
    node *past = NULL;
    node *fut = NULL;
    while(pre)
    {
        fut = pre -> next;
        pre -> next = past;
        past = pre;
        pre = fut;
    }
    head = past;

    //displaying linked list

    node* temp = head;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}