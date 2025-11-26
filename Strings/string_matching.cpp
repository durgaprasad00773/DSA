#include <iostream>
#include<vector>
using namespace std;
int main()
{
    string str = "abcdaabceaabceaabdop";
    string x = "aabceaabdo";
    int n = str.length();
    int m = x.length();
    vector <int> v(m,0);
    int first = 0;
    int second = 0;
    int pre = 0;
    int suf = 1;
    while(suf < m)
    {
        if(x[pre] == x[suf])
        {
            v[suf] = pre+1;
            pre++;
            suf++;
        }
        else
        {
            if(pre == 0)
            {
                v[suf] = 0;
                suf++;
            }
            else
            {
                pre = v[pre-1];
            }
            
        }
    }
    while(first < n)
    {
        if(str[first] == x[second])
        {
            first++;
            second++;
        }
        else{
            if(second == 0)
            {
                first++;
            }
            else{
                second = v[second-1];
            }
        }
        if(second == m)
        {
            break;
        }
    }
    cout << first-second;
}