#include <iostream>
using namespace std;
int did(int n);
int main()
{
    cout << did(10342);
}
int did(int n)
{
    if(n < 1)
    {
        return 1;
    }
    return (n%10)*did(n/10);
}