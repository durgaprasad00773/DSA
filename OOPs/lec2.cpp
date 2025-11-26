#include <iostream>
using namespace std;
class customer
{
    string name;
    int acc;
    int bal;
    public:
    customer()
    {
        cout << "Hi";
    }
    customer(string a, int b, int c)
    {
        name = a;
        acc = b;
        bal = c;
    }
    customer(customer &b)
    {
        name = b.name;
        acc = b.acc;
        bal = b.bal;
    }
    customer(string name)
    {
        this -> name = name;
        cout << name;
    }
    void get()
    {
        cout << name << "  "<< acc << "  " << bal;
    }
};
int main()
{
    // customer a1("prasad", 123, 100);
    // customer a2(a1);
    // a2.get();
    // customer a3;
    // //assignment operator
    // a3 = a2;
    // a3.get();
    customer a1("1"), a2("2"), a3("3"); 
}