#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node
{
    public:
    int data;
    node* next, *prev;
    node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};
class deq
{
    node* front;
    node* rear;
    int size;
    public:
    deq(int x = 0)
    {
        size = x;
        front = NULL;
        rear = NULL;
    }
    int length()
    {
        return size;
    }
    void push_front(int value)
    {
        if(size == 0)
        {
            node* temp = new node(value);
            front = temp;
            rear = temp;
        }
        else{
            node* temp = new node(value);
            temp -> next = front;
            front -> prev = temp;
            front =  temp;        
        }
        size++;
        cout << "push_front " << value << endl;
    }
    void push_back(int value)
    {
        if(size == 0)
        {
            node* temp = new node(value);
            front = temp;
            rear = temp;
        }
        else{
            node* temp = new node(value);
            temp -> prev = rear;
            rear -> next = temp;
            rear = temp;
        }
        size++;
        cout << "push_back " << value << endl;
    }
    int pop_front()
    {
        if(size == 0)
        {
            return -1;
        }
        if(size == 1)
        {
            size--;
            int x = front -> data;
            node* temp = front;
            front = NULL;
            rear = NULL;
            delete temp;
            return x;
        }
        size--;
        node* temp = front;
        front = temp -> next;
        front -> prev = NULL;
        int x = temp -> data;
        delete temp;
        return x;
    }
    int pop_back()
    {
        if(size == 0)
        {
            return -1;
        }
        if(size == 1)
        {
            size--;
            node* temp = rear;
            int x = temp -> data;
            front = NULL;
            rear = NULL;
            delete temp;
            return x;
        }
        size--;
        node* temp = rear;
        rear = rear -> prev;
        rear -> next = NULL;
        int x = temp -> data;
        delete temp;
        return x;
    }
    int start()
    {
        if(size == 0)
        {
            return -1;
        }
        else
        {
            return front -> data;
        }
    }
    int end()
    {
        if(size == 0)
        return -1;

        else
        return rear->data;
    }
};
int main()
{
    deq d;
    d.push_back(34);
    cout << d.start();
}