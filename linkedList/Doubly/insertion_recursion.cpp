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
node* list(int arr[], int n, int index, node* ptr)
{
    if(index >= n)
    {
        return NULL;
    }
    node* temp = new node(arr[index]);
    temp -> prev = ptr;
    temp -> next = list(arr, n, index+1, temp);
    return  temp;
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = list(arr, n, 0, NULL);

    //displaying the node in doubly linked list

    node* temp = head;
    while(temp -> next)
    {
        temp = temp -> next;
    }
    cout << "NULL";
    while(temp)
    {
        cout << " <- " << temp -> data << " -> ";
        temp = temp -> prev;
    }
    cout << "NULL";
}