#include <iostream>
using namespace std;
int main()
{
    string ip;
    cin >> ip;
    string ans;
    int i=0; 
    while (i<ip.size())
    {
        if(ip[i] == '.')
        {
            ans += "[.]"; 
        }
        else{
            ans += ip[i];
        }
        i++;
    }
    cout << ans;
}