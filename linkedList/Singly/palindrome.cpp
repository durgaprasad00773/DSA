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
    int arr[] = {1, 2, 3, 2 ,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* head = list(arr, n, 0);

    //displaying the linkedlist
    node* temp = head;
    while(temp)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}