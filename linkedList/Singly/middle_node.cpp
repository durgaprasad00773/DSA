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

    //finding the middle node

    int count = 0;
    node* curr = head;
    while(curr)
    {
        count++;
        curr = curr -> next;
    }
    count = count / 2;
    curr = head;
    while(count)
    {
        curr = curr -> next;
        count--;
    }
    cout << curr -> data;
    //displaying linked list

    // node* temp = head;
    // while(temp)
    // {
    //     cout << temp -> data << " -> ";
    //     temp = temp -> next;
    // }
    // cout << "NULL";
}