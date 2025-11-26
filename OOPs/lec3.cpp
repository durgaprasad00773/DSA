#include <iostream>
using namespace std;
class customer
{
    string name;
    int acc;
    int bal;
    public:
    //default constructor
    customer()
    {
        cout << "constructor is called";
    }
    //parametrised constructor is having the parameters

// same functiion name , but different no. of parameters , constructor overloading

    // this is overoaded constructor
    // customer(string name, int acc, int bal)
    // {
    //     this -> name = name;
    //     this -> acc = acc;
    //     this -> bal = bal;           //this pointer is pointing towards the object
    // }

    //inline constructor
    inline customer(string a, int b, int c) : name(a), acc(b), bal(c)
    {

    }
    void get()
    {
        cout << name << "  " << acc << "  " << bal;
    }
};
int main()
{
    customer a1("prasad", 213723,12344);
    a1.get();
}