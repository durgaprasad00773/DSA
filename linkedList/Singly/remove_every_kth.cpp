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
    //base condition
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = list(arr, n, 0);
    //countint the no. of nodes

    int count = 0;
    node *curr = head;
    while(curr)
    {
        count++;
        curr = curr -> next; 
    }

    int x = 2;

    //deleting the every xth element

    curr = head;
    node *prev = NULL;
    while(curr != NULL)
    {
        if(x == 1)
        {
            prev -> next = curr -> next;
            delete curr;
            curr = prev -> next;
            x = 2;
        }
        else{
            prev = curr;
            curr = curr -> next;
            x--;
        }


    }


    //displaying the linkedlist
    node * temp = head;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}