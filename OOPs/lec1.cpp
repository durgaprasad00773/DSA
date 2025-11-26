#include <iostream>
#include <string>
using namespace std;
class student{
    string name;
    int roll;
    string grade;
    public:
    void set(string n, int r, string g)
    {
        name = n;
        roll = r;
        grade = g;
    }
    void getName()
    {
        cout << name;
    }
    void getRoll()
    {
        cout << roll;
    }
    string getGrade(int pin)
    {
        if(pin == 1234)
        {
            return grade;
        }
        else{
            return " ";
        }
    }
};
int main()
{
    student s1;
    //s1.set("prasad", 21, "A+");
    cout << sizeof(s1);
    
}