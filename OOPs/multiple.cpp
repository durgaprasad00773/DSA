#include <iostream>
using namespace std;
class youtuber
{
    protected:
    string channel;
    int subs;
    public:
    void youtube()
    {
        cout << "channel name: " << channel << endl << "subscribers : " << subs << endl;
    }
};
class teacher
{
    protected:
    string subject;
    public:
    void teach()
    {
        cout << "Subject : " << subject << endl ;
    }
};
class client:public teacher, public youtuber
{
    string name;
    string spec;
    public:
    client(string name, string spec, string subject, string channel, int subs)
    {
        this -> name = name;
        this -> spec = spec;
        this -> subject = subject;
        this -> channel = channel;
        this -> subs = subs;
    }
    void display()
    {
        cout << name << endl << spec << endl << subject << endl << channel << endl << subs << endl;
    }
};
int main()
{
    client a1("prasad", "ME", "PDS", "CoderArmy", 234987);
    a1.teach();
}