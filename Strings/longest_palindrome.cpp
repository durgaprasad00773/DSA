#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter a string : ";
    cin >> s;
    int a[26]={0};
    int A[26]={0};
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] - 'a' > 0)
        {
            a[s[i]-'a'] += 1;
        }
        else{
            A[s[i]-'A'] += 1;
        }
    }
    int ans = 0;
    for(int i=0; i<26; i++)
    {
        if(a[i]  % 2 == 0)
        {
            ans = ans + a[i];
        }
        else
        {
            ans += (a[i] - 1);
        }
    }
    for(int i=0; i<26; i++)
    {
        if(A[i]  % 2 == 0)
        {
            ans = ans + A[i];
        }
        else
        {
            ans += (A[i] - 1);
        }
    }
    int temp = ans;
    for(int i=0; i<26; i++)
    {
        if(a[i] % 2 != 0)
        {
            ans = ans + 1;
            break;
        }
    }
    if(temp == ans)
    {
        for(int i=0; i<26; i++)
        {
            if(A[i] % 2 != 0)
            {
                ans = ans + 1;
                break;
            }
        }
    }
    cout << "The longest possible palindrome  : " << ans; 
}