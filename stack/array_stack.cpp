#include <iostream>
using namespace std;
class stack
{
    int* arr;
    int size;
    int top;
    public:
    stack(int s)
    {
        size = s;
        arr = new int[size];
        top = -1;
    }
    void push(int value)
    {
        if(top == size-1)
        {
            cout << "Stack Overflow";
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow";
        }
        else
        {
            top--;
        }
    }
    void peak()
    {
        if(top == -1)
        {
            cout << "Stack is Empty";
        }
        else{
            cout << arr[top];
        }
    }
    void isEmpty()
    {
        if(top == -1)
        {
            cout << "True";
        }
        else{
            cout << "False";
        }
    }
    void display()
    {
        for(int i = top; i>=0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    stack s1(1);
    s1.push(1);
    s1.push(34);
}