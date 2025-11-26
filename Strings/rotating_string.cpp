#include <iostream>
using namespace std;
int main()
{
    string s = "amazon";
    string s1 = "namazo";
    for(int k=0; k<2; k++)
    {
        char temp = s[s.size() - 1];
        for(int i=s.size()-1; i>0; i--)
        {
            s[i] = s[i-1];
        }
        s[0] = temp;
    }
   cout << s;
}