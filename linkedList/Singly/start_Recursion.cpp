#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};
node* list(int arr[], int n, node* ptr, int index)
{
    if(index == n)
    {
        return ptr;
    }
    node *temp = new node(arr[index]);
    temp -> next = ptr;
    ptr = temp;
    return list(arr, n, ptr, index+1);
}
int main()
{
    int arr[] = {2, 4, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = 0;
    node *ptr = NULL;
    node *head = list(arr, n, ptr, index);

    node* temp;
    temp = head;
    while(temp)
    {
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "Null";
}