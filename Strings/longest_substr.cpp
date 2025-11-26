#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main()
{
    string str = "ababca";
    int n = str.length();
    int left = 0;
    int right = 0;
    int len = 0;
    vector <int> v(256,0);
    while(right < n)
    {
        while(v[str[right]])
        {
            v[str[left]] = 0;
            left++;
        }
        v[str[right]]++;
        len = max(len, right-left+1);
        right++;
    }
    cout << len;
}