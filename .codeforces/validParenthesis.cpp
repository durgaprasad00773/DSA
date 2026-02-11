#include <iostream>
#include <string>
using namespace std;
bool isValid(string s)
{
    int a=0,b=0,c=0,x=0,y=0,z=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '(')
        {
            a++;
        }

    }
    if(a == 1)
    {
        return true;
    }
}
int main()
{
    string str = "([)]";
    cout << isValid(str);
}