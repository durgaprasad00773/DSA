#include <iostream>
using namespace std;
void toh(int n, int s, int h, int d)
{
    //base condition
    if(n==1)
    {
        cout << "move disk "<< n << "from " << s << " to " << d << endl;
        return;
    }
    
    
    toh(n-1, s, d, h);
    cout << "move disk "<< n << "from " << s << " to " << d << endl;
    toh(n-1, h, s, d);
}
int main()
{
    int n = 3;
    toh(n, 1,2,3);
}