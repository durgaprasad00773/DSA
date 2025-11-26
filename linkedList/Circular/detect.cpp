#include <iostream>
#include <vector>
#include <unordered_map>
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};;
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = 0;
    node *head = list(arr, n, index);
    //linking a tail to the linked_list

    node* tail = head;
    while(tail -> next)
    {
        tail = tail -> next;
    }
    //tail -> next = head -> next -> next -> next; // we have made a loop
    unordered_map<node*, bool> visited;
    node* curr = head;
    while (curr)
    {
        if(!visited[curr])
        {
            visited[curr] = 1;
        }
        else{
            cout << "loop";
            return 0;
        }
        curr = curr -> next;
    }
    cout << "not a loop";
    

    


    //displaying the nodes of linked_list
    
    // node* temp;
    // temp = head;
    // while(temp)
    // {
    //     cout << temp->data << " -> ";
    //     temp = temp -> next;
    // }
    // cout << "Null";
}