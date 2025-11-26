#include <iostream>
using namespace std;
class human
{
    protected:
    string name;
    public:
    human(string name)
    {
        this -> name = name;
    }
    human()
    {

    }
};
class student:public human{
    int roll;
    public:
    student(string name, int roll):human(name)
    {
        this -> roll = roll;
    }
    void profile()
    {
        cout << "name : " <<  name << endl << "roll : " << roll << endl;
    }
};
class teacher : public human{
    int salary;
    public:
    teacher(string name, int salary):human(name)
    {
        this -> salary = salary;
    }
    void bio()
    {
        cout << "name : " <<  name << endl << "salary : " << salary << endl;
    }
};
int main()
{
    student a1("prasad", 21);
    a1.profile();
    teacher a2("ravi", 234566);
    a2.bio();
}