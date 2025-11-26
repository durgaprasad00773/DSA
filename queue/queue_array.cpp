#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    queue(int n)
    {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    //isEmpty

    bool isEmpty()
    {
        if(rear == -1)
        {
            return 1;
        }
        return 0;
    }

    //isFull

    bool isFull()
    {
        if(rear == size -1)
        {
            return 1;
        }
        return 0;
    }

    //push

    void push(int x)
    {
        if(isEmpty())
        {
            front++;
            rear++;
            arr[rear] = x;
            cout << x << " pushed into queue" << endl;
        }
        else if(isFull())
        {
            cout << "queue overflow" << endl;
        }
        else{
            rear++;
            arr[rear] = x;
            cout << x << " pushed into queue" << endl;
        }
    }

    //pop

    void pop()
    {
        if(isEmpty())
        {
            cout << "Queue Underflow" << endl;
        }
        else{
            int ele = arr[front];
            front++;
            if(front > rear)
            {
                front = -1;
                rear = -1;
            }
            cout << ele << " poped from queue" << endl;
        }
    }

    //start

    int start()
    {
        if(isEmpty())
        {
            return -1;
        }
        else{
            return arr[front];
        }
    }
};
int main()
{
    queue q(10);
    q.push(99);
    //q.push(12);
    q.push(54);
    q.push(34);
    q.pop();
    q.pop();
    cout << q.start();
}