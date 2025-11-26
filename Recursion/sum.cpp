#include <iostream>
using namespace std;
int sum(int n);
int main()
{
    cout << sum(5);
}
int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n + sum(n-1);
}
