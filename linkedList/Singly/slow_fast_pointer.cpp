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

    //finding the middle node using slow and fast pointer

    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    cout << slow -> data;

}