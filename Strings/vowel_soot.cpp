#include <iostream>
using namespace std;
int main()
{
    string s = "lEetcOde";
    int a[26] = {0};
    int A[26] = {0};
    int i=0; 
    while(s[i] != '\0')
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            a[s[i] - 'a'] += 1;
            s[i] = '#';
        }
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
        A[s[i] - 'A'] += 1;
        s[i] = '#';
        }
        i++;
    }
    i=0; 
    string ans;
    //upper case
    for(int j=0; j<26; j++)
    {
        while(A[j])
        {
            ans += j+'A';
            A[j]--;
        }
    }
    for(int j=0; j<26; j++)
    {
        while (a[j])
        {
           ans += j+'a';
           a[j]--;
        }
        
    }
    i = 0;
    int k=0;
    while (s[i] != '\0')
    {
        if(s[i] == '#')
        {
            s[i] = ans[k];
            k++;
        }
        i++;
    }
    cout << s;
}