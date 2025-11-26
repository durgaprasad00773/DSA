#include <iostream>
using namespace std;
class customer
{
    string name;
    int acc, bal;
    static int total_customers;
    static int total_money;

    public:
    customer(string name, int acc, int bal)
    {
        this -> name = name;
        this -> acc = acc;
        this -> bal = bal;
        total_customers++;
        total_money+=bal;
    }
    void display()
    {
        cout<< "Name : " << name << endl << "Acc_number : " << acc << endl << "Balance : " << bal << endl;
    }
    void deposit(int amount)
    {
        if(amount > 0)
        {
            bal+=amount;
            total_money+=amount;
        }
        else{
            cout << "Invalid amount !";
        }
    }
    void withdraw(int amount)
    {
        if(amount > 0)
        {
            bal-=amount;
            total_money-=amount;
        }
        else{
            cout << "Invalid amount !";
        }
    }
    static void customers()
    {
        cout << "Total_number_of_customers : " <<  total_customers << endl;
    }
    static void money()
    {
        cout << "Total_money_in_the_bank : " << total_money<< endl;
    }
};
//Encapsulation : It is used for data security & it helps in code maintainance
//Abstraction : 
int customer::total_customers = 0;
int customer::total_money = 0;
int main()
{
    customer a1("prasad", 1000, 12000);
    customer a2("shanmukh", 1001, 15000);
    customer a3("laxmi", 1002, 10000);
    a1.deposit(-12);
    // customer::money();
    // customer::customers();
    // a1.display();
}