#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

//function to create linkedlists

node* list(int arr[], int n, int index)
{
    //base condition
    if(index >= n)
    {
        return NULL;
    }
    node* temp = new node(arr[index]);
    temp -> next = list(arr, n, index+1);
    return temp;
}

// function to reverse the linkedlists

node* reverse(node* head)
{
    node* pre = head;
    node* past = NULL;
    node* fut = NULL;
    while(pre)
    {
        fut = pre -> next;
        pre -> next = past;
        past = pre;
        pre = fut;
    }
    head = past;
}

int main()
{
    int arr1[] = {8,7,9,9,1,0,4,7};
    int arr2[] = {8,9,1,3,0,0,4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    node* head1 = list(arr1, n1, 0);
    node* head2 = list(arr2, n2, 0);

    head1 = reverse(head1);
    head2 = reverse(head2);


    node* head = new node(0);
    node* tail = head;
    int carry = 0;
    node* curr1 = head1;
    node* curr2 = head2;
    while(curr1 && curr2)
    {
        int sum = curr1 -> data + curr2 -> data + carry;
        carry = sum / 10;
        tail -> next = new node(sum%10);
        tail = tail -> next;
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    while(curr1)
    {
        int sum = carry + curr1 -> data;
        carry = sum / 10;
        tail -> next = new node(sum%10);
        tail = tail -> next;
        curr1 = curr1 -> next;
    }
    while(curr2)
    {
        int sum = carry + curr2 -> data;
        carry = sum / 10;
        tail -> next = new node(sum%10);
        tail = tail -> next;
        curr2 = curr2 -> next;
    }

    while(carry)
    {
        tail -> next = new node(carry%10);
        tail = tail -> next;
        carry /= 10;
    }

    node* temp = head;
    head = head -> next;
    delete temp;

    //reversing the answer linkedlist

    head = reverse (head);


    //displaying the linked lists

    temp = head;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << " NULL ";
}