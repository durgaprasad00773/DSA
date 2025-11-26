#include <iostream>
using namespace std;
int reduce(int n , int steps)
{
    if (n ==0 )
    {
        return steps;
    }
    if(n%2 == 0)
    {
        return reduce(n/2, steps+1);
    }
    else if (n%2 == 1)
    {
        return reduce (n-1, steps+1);
    }
    
}
int main()
{
    int n = 41;
    int steps = 0;
    cout  << reduce(n,steps);
}