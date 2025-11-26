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
    //we have created a linkedlist with only 0, 1, and 2

    int arr[] = {1, 2, 0, 2, 1, 0, 0, 1, 1, 2, 0, 1, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = 0;
    node *head = list(arr, n, index);

    //create 3 heads 

    node *head0 = NULL, *head1 = NULL, *head2 = NULL;
    node *tail0 = NULL, *tail1 = NULL, *tail2 = NULL;
    while(head)
    {
        if(head -> data == 0)
        {
            if(head0 == NULL)
            {
                head0 = head;
                tail0 = head0;
                head = head -> next;
                tail0 -> next = NULL;
            }
            else{
                tail0 -> next = head;
                head = head -> next;
                tail0 = tail0 -> next;
                tail0 -> next = NULL;
            }
        }
        else if(head -> data == 1)
        {
            if(head1 == NULL)
            {
                head1 = head;
                tail1 = head1;
                head = head -> next;
                tail1 -> next = NULL;
            }
            else{
                tail1 -> next = head;
                head = head -> next;
                tail1 = tail1 -> next;
                tail1 -> next = NULL;
            }
        }
        else{
            if(head2 == NULL)
            {
                head2 = head;
                tail2 = head2;
                head = head -> next;
                tail2 -> next = NULL;
            }
            else{
                tail2 -> next = head;
                head = head -> next;
                tail2 = tail2 -> next;
                tail2 -> next = NULL;
            }
        }
    }

    //now we have to connect the os, 1s, and 2s

    tail0 -> next = head1;
    tail1 -> next = head2;
    head = head0;


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