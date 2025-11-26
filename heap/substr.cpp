#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "ADOBECODEBANC";
    string c = "ABC";
    unordered_map<char , int> mp;
    for(int i=0; i<c.size(); i++)
    {
        mp[c[i]]++;
    }

    int total = c.size();
    int start =0;
    int end = 0, ans = INT_MAX, index = -1;
    while(end < str.size())
    {
        mp[str[end]]--;
        if(mp[str[end]] >= 0)
        {
            total--;
        }
        while(total == 0 && start <= end)
        {
            index = start;
            if(ans > end-start+1)
            {
                ans = end-start+1;
            }
            mp[str[start]]++;
            if(mp[str[start]] > 0)
            total++;

            start++;
        }
        end++;


    }
    if(index == -1)
    cout << "";

    else
    {
        cout << str.substr(index, ans);
    }

}