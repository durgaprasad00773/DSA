#include <iostream>
using namespace std;
class animal
{
    public:
    virtual void sound()
    {
        cout << "HuHu";
    }
};
class dog:public animal
{
    public:
    void sound()
    {
        cout << "Bark";
    }
};
int main()
{
    animal *p = new dog;
    p->sound();
    delete p;
}