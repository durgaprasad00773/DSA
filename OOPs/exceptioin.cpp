#include <iostream>
#include <exception>
using namespace std;
class customer
{
    string name;
    int acc, bal;
    public:
    customer(string name, int bal, int acc)
    {
        this -> name = name;
        this -> bal = bal;
        this -> acc = acc;
    }
    void deposit(int amount)
    {
        if(amount <= 0)
        {
            throw runtime_error("amount should be greater than 0");
        }
        else{
            bal += amount;
            cout << "transaction successful !";
        }
    }
    void withdraw(int amount)
    {
        if(amount >0 && amount <= bal)
        {
            bal -= amount;
            cout << "transaction successful !";
        }
        else{
            if(amount < 0)
            {
                throw runtime_error("amount should be greater than 0");
            }
            else{
                throw "Insufficient Balance !";
            }
        }
    }
};
int main()
{
    customer a1("prasad", 1000, 102210048);
    try{
        a1.withdraw(3000);
    }
    catch(const runtime_error &e)
    {
        cout << "Error : " << e.what();
    }
    catch(...)
    {
        cout << "Exception Occured";
    }
    
}