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
node* list(int arr[], int n, int index)
{
    if(index >= n)
    {
        return NULL;
    }

    node* temp = new node(arr[index]);
    temp -> next =  list(arr, n, index+1);
    return temp;
}
int main()
{
    int arr[] = {2, 4, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = 0;
    node *head = list(arr, n, index);

    //displaying the nodes of linked_list
    
    node* temp;
    temp = head;
    while(temp)
    {
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "Null";
}