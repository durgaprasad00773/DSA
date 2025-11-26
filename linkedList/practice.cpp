#include <iostream>
#include <unordered_map>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* arb;
    node(int value)
    {
        data = value;
        next = NULL;
        arb = NULL;
    }
};
node* list(int arr[], int n, int index)
{
    if(index >= n)
    {
        return NULL;
    }
    node* temp = new node(arr[index]);
    temp -> next = list(arr, n, index+1);
    return temp;
}
int main()
{
    node* head;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    head = list(arr, n, 0);
    node* curr = head;
    curr -> arb = head -> next -> next; //1
    curr = curr -> next;
    curr -> arb = head; //2
    curr = curr -> next;
    curr -> arb = curr -> next -> next;//3
    curr = curr -> next;
    curr -> arb = head -> next -> next;
    curr = curr -> next;
    curr -> arb = head -> next;


    //now cloning the linkedlist
    node* copyhead = NULL;
    node* copytail = NULL;
    curr = head;
    while(curr)
    {
        if(copyhead == NULL)
        {
            copyhead = new node(curr -> data);
            copytail = copyhead;
        }
        else
        {
            copytail -> next = new node(curr -> data);
            copytail = copytail -> next;
        }
        curr = curr -> next;
    }

    //combining original and copy

    node* curr1 = head;
    node* curr2 = copyhead;
    node* front1;
    node* front2;
    while(curr1)
    {
        front1 = curr1 -> next;
        front2 = curr2 -> next;
        curr1 -> next = curr2;
        curr2 -> next = front1;
        curr1 = front1;
        curr2 = front2;
    }

    //connecting random pointers

    curr1 = head;
    while(curr1)
    {
        curr2 = curr1 -> next;
        if(curr1 -> arb)
        {
            curr2 -> arb = curr1 -> arb -> next;
        }
        curr1  = curr2 -> next;
    }

    //disconnecting original and copy

    curr1 = head;
    while(curr1 -> next)
    {
        front1 = curr1 -> next;
        curr1 -> next = front1 -> next;
        curr1 = front1;
    }

    //displaying the random

    // curr = copyhead;
    // while(curr)
    // {
    //     cout << curr -> arb -> data << endl;
    //     curr = curr -> next;
    // }

    //displaying the linkedlist

    node* temp =  copyhead;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next; 
    }
    cout <<  " NULL ";
}