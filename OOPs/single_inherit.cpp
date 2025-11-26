#include <iostream>
using namespace std;
class human
{
    string religion, color;
    protected:
    string name;
    int age;
    int weight;
    human(string name, int age , int weight)
    {
        this -> name = name;
        this -> age = age;
        this -> weight = weight;
    }
};
class student : private human
{
    private:
    int roll, fee;
    public:
    student(string name, int age, int weight, int roll, int fee):human(name, age,weight)
    {
        this -> roll = roll;
        this -> fee = fee;
    }
    void display()
    {
        cout << "name : " << name << "\nage : " << age << "\nweight : " << weight << "\nroll : " << roll << "\nfee  : " << fee;
    }
};
int main()
{
    student a1("prasad", 21, 60, 69, 62500);
    a1.display();
}