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
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    node *head = NULL;
    node *tail = NULL;
    for(int i=0; i<n; i++)
    {
        if(head == NULL)
        {
            head = new node(arr[i]);
            tail = head;
        }
        else{
            node *temp = new node(arr[i]);
            tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
        }
    }

    //deletion of node at beginning

    node * curr = head;
    // if(head != NULL)
    // {
        //for list containing only one node

    //     if(head -> next == NULL)
    //     {
    //         head = head -> next;
    //         delete curr;
    //     }
    //     head = head -> next;
    //     head -> prev = NULL;
    //     delete curr;
    // }

    //deletion at the ending of the list

    // curr = head;
    // while(curr -> next)
    // {
    //     curr = curr -> next;
    // }
    // if(head != NULL)
    // {
    //     if(head -> next == NULL)
    //     {
    //         head = head -> next;
    //         delete curr;
    //     }
    //     curr -> prev -> next = NULL;
    //     delete curr;
    // }

    // deleting node at any desired position

    int pos = 5;
    curr = head;
    if(head != NULL)
    {
        if(pos == 1)
        {
            if(head -> next == NULL)
            {
                head = head -> next;
                delete curr;
            }
            else{
                head = head -> next;
                head -> prev = NULL;
                delete curr;
            }
        }

        // pos is not equal to 1

        else{
            while(--pos)
            {
                curr = curr -> next;
            }
            if(curr -> next == NULL)
            {
                if(head -> next == NULL)
                {
                    head = head -> next;
                    delete curr;
                }
                else{
                    curr -> prev -> next = NULL;
                    delete curr;
                }
            }
            else{
                curr -> prev -> next = curr -> next;
                curr -> next -> prev = curr -> prev;
                delete curr;
            }
        }

    }
    

    //displaying the doubly linked list
    
    node* temp = head;
    cout << "NULL";
    while (temp != NULL) {
        cout << " <- " << temp->data << " ->";
        temp = temp -> next;
    }
    cout << " NULL" << endl;


}