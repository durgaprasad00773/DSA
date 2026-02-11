#include <iostream>
using namespace std;
struct student
{
    string name;
    string roll;
    string department;
};
class stack
{
    int size;
    int top;
    student* arr;
    public:

    //constructor

    stack(int n)
    {
        size = n;
        arr = new student[n];
        top = -1;
    }

    //destructor

    ~stack()
    {
        delete arr;
    }

    //isEmpty

    bool isEmpty()
    {
        return top == -1;
    }

    //isFull

    bool isFull()
    {
        return top == size-1;
    }

    //push

    void push(student s)
    {
        if(isFull())
        {
            cout << "Stack Overflow" << endl;
            return ;
        }

        arr[++top] = s;
        cout << "student pushed successfully" << endl;
    }

    //pop

    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return ;
        }

        int index = top;
        top--;

        cout << "name : " << arr[index].name << endl << "roll : " << arr[index].roll << endl << "dept : " << arr[index].department << endl << "popped successfully" << endl;
    }

    //peek

    void peek()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty";
            return ;
        }

        cout << "name : " << arr[top].name << endl << "roll : " << arr[top].roll << endl << "dept : " << arr[top].department << endl;
    }

    //print

    void print()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty";
        }

        for(int i=top; i>=0; i--)
        {
            cout << "Student name : " << arr[i].name << endl;
            cout << "Roll No : " << arr[i].roll << endl;
            cout << "Department : " << arr[i].department << endl;

            cout << endl;

        }
    }
};
int main()
{
    int size;
    cout << "Enter Size of the Stack : ";
    cin >> size;

    stack st(size);

    int choice;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push Student\n";
        cout << "2. Pop Student\n";
        cout << "3. View Top Student\n";
        cout << "4. Print Stack\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                student a1;
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, a1.name);
                cout << "Enter Roll No: ";
                cin >> a1.roll;
                cin.ignore();
                cout << "Enter Department: ";
                getline(cin, a1.department);
                st.push(a1);
                break;
            }
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                st.print();
                break;
            case 5:
                if (st.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is NOT Empty.\n";
                break;
            case 6:
                if (st.isFull())
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is NOT Full.\n";
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}