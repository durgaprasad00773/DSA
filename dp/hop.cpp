#include <iostream>
#include <vector>
using namespace std;
int hop(int n)
{
    if(n==0)
    return 1;

    if(n<0)
    return 0;

    return hop(n-1)+hop(n-2)+hop(n-3);
}
int main()
{
    cout << "Enter a Number : ";
    int n;
    cin >> n;

    cout << hop(n);
}