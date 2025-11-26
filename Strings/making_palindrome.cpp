#include <iostream>
using namespace std;
int main()
{
    string str = "abc";
    int n = str.length();
    int start = 0;
    int end = n-1;
    int count = 0;
    while(start < end)
    {
        if(str[start] != str[end])
        {
            count++;
            end--;
        }
        else{
            start++;
            end--;
        }
    }
    cout << count;
}