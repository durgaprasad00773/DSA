#include <iostream>
using namespace std;
int main()
{
    string s ="abbaabbaekkadikyi";
    int n = s.size();
    int arr[26] = {0};
    for(int i=0; i<n; i++)
    {
        arr[s[i]-'a'] += 1;
    }
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<arr[i]; j++)
        {
            char c = 'a'+i;
            cout << c;
        }
    }
}