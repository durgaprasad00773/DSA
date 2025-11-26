#include <iostream>
using namespace std;
class Human
{
    string religion, color;
    protected:
    string name;
    int age;
    int weight;
};
class Student:public Human
{
    protected:
    int roll;
    int fee;
};
class _10:public Student
{
    string section;
    public:
    _10(string name, int age, int weight, string section, int roll, int fee)
    {
        this -> name = name;
        this -> age = age;
        this -> weight = weight;
        this -> section = section;
        this -> roll = roll;
        this -> fee = fee;
    }
    void display()
    {
        cout << name << endl << age << endl  << weight << endl  << section  << endl << roll << endl << fee;
    }
};
class Teacher:public Human
{
    string id;
    int salary;
};
int main()
{
    _10 a1("prasad", 21, 59, "B", 69, 62500);
    a1.display();
}