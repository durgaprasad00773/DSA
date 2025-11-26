#include <iostream>
#include <stack>
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
class Nstack
{
    public:
    int* arr; //to store data
    node** top; //to store addresses of pointers pointing to node type
    stack<int> st; //to store empty slots
    int size;
    Nstack(int N, int S)
    {
        top = new node*[N];
        arr = new int[S];
        size = S;
        for(int i=0; i<N; i++)
        {
            top[i] = NULL;
        }
        for(int i=0; i<S; i++)
        {
            st.push(i);
        }
    }

    //push operation

    bool push(int x, int n)
    {
        if(st.empty())
        {
            return 0;
        }
        int index = st.top();
        st.pop();
        arr[index] = x;
        if(top[n-1]  == NULL)
        {
            top[n-1] = new node(index);
        }
        else{
            node* temp = new node(index);
            temp -> next = top[n-1];
            top[n-1] = temp;
        }
        return 1;

    }

    //pop operation

    int pop(int n)
    {
        if(top[n-1] == NULL)
        {
            return -1;
        }
        int index = top[n-1] -> data;
        node* temp = top[n-1];
        top[n-1] = temp -> next;
        delete temp;

        st.push(index);
        return arr[index];
    }
};
int main()
{
    Nstack a1(3, 10);   
    a1.push(99, 1);
    cout << a1.pop(1);
    cout << a1.pop(1);
}