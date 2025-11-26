#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str = "abcabdabcabcabd";
    int n = str.length();
    vector <int> lps(n,0);
    int pre = 0;
    int suf = 1;
    while(suf < n)
    {
        if(str[pre] == str[suf])
        {
            lps[suf] = pre+1;
            suf++;
            pre++;
        }
        else{
            if(pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }

    }
    for(int i=0; i<n; i++)
    {
        cout << lps[i] << "  ";
    }
}