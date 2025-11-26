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
    head -> next -> next -> next -> next = new node(50);

    // copying them to vector
    vector <int> arr;
    node* ptr = head;
    while(ptr)
    {
        arr.push_back(ptr -> data);
        ptr = ptr -> next;
    }

    //making them in reverse order

    int start = 0;
    int end = arr.size()-1;
    while(start < end)
    {
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }

    //copyinig elements to array

    ptr = head;
    int i=0;
    while(ptr)
    {
        ptr -> data = arr[i];
        ptr = ptr -> next;
        i++;
    }

    //displaying linked list

    node* temp = head;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}