#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class deq
{
    int *arr;
    int size;
    int front, rear;
    public:
    deq(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    //empty
    bool empty()
    {
        if(front == -1)
        return 1;

        else
        return 0;
    }
    //push_front

    void push_front(int val)
    {
        if((rear+1)%size == front)
        {
            cout << "Deque Overflow";
            return ;
        }
        else
        {
            if(empty())
            {
                front++;
                rear++;
                arr[front] = val;
            }
            else{
                front = (front -1 + size)%size;
                arr[front] = val;
            }
        }
        cout << "pushed " << val << " at front" << endl;
    }
    //push_back

    void push_back(int val)
    {
        if((rear+1)%size == front)
        {
            cout << "Deque Overflow";
            return ;
        }
        else
        {
            if(empty())
            {
                front++;
                rear++;
                arr[rear] = val;
            }

            else{
                rear = (rear + 1)%size;
                arr[rear] = val;
            }
        }
        cout << "pushed " << val << " at back" << endl;
    }

    //pop_front

    void pop_front()
    {
        if(empty())
        {
            cout << "Deque Underflow";
            return ;
        }
        else{
            if(front == rear)
            {
                front = rear = -1;
                return ;
            }
            front = (front+1)%size;
        }
        cout << "popped from front" <<  endl;
    }

    //pop_back

    void pop_back()
    {
        if(empty())
        {
            cout << "Deque Underflow";
            return ;
        }
        else{
            if(front == rear)
            {
                front = rear = -1;
                return ;
            }
            rear = (rear -1 + size)%size;
        }
        cout << "popped from back" <<  endl;
    }

    //start

    int start()
    {
        if(empty())
        return -1;

        else
        return arr[front];
    }

    //end

    int end()
    {
        if(empty())
        return -1;

        else
        return arr[rear];
    }


};
int main()
{
    deq d(5);
    d.pop_back();

}