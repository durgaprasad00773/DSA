#include <iostream>
using namespace std;
int main()
{
    string s = "subbus";
    string temp = s;
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        swap(s[start] , s[end]);
        start++;
        end--;
    }
    if(temp == s)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not  a palindrome";
    }
    
}