#include <iostream>
#include <vector>
using namespace std;
int fib(int n)
{
    int t1 = 0;
    int t2 = 1;

    if(n < 2)
    return n;

    int curr;
    for(int i=2; i<=n; i++)
    {
        curr = t1+t2;
        t1 = t2;
        t2 = curr;
    }

    return curr;
}
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    cout << fib(n);
}