#include <iostream>
using namespace std;
class youtuber
{
    protected:
    string channel;
    int subs;
    public:
    youtuber()
    {
        cout << " Hello youtuber" << endl;
    }
    ~youtuber()
    {
        cout << "Bye youtuber" << endl;
    }
};
class teacher
{
    protected:
    string subject;
    public:
    teacher()
    {
        cout << "Hello teacher" << endl;
    }
    ~teacher()
    {
        cout << " Bye teacher" << endl; 
    }
};
class client:public youtuber, public teacher
{
    string name;
    string spec;
    public:
    client()
    {
        cout << "Hello client" << endl;
    }
    ~client()
    {
        cout << "Bye client" << endl;
    }
};
int main()
{
    client a1;
}