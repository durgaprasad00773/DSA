#include <iostream>
using namespace std;
int winner(int n, int k)
{
    //base condition
    if(n==1)
    {
        return 0;
    }
    return (winner(n-1, k)+k)%n;
}
int main()
{
    int n = 7;
    int k = 4;
    cout << winner(n, k);
}