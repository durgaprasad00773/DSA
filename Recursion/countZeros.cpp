#include <iostream>
using namespace std;
int count(int n, int z);
int main()
{
    cout << count(30207, 0);
}
int count(int n, int z)
{
    if(n==0); 
    {
        return z;
    }
    if(n%10 == 0)
    {
        return count(n/10, z+1);
    }
    return count(n/10 , z);
}