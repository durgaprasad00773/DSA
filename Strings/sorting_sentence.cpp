#include <iostream>
using namespace std;
int main()
{
    string s = "sentence4 is2 this1 a3";
    int n = s.size();
    int count = 0;
    int i = 0;
    string temp;
    string arr[10];
    while(i<n)
    {
        if(s[i] == ' ')
        {
            int pos = temp[temp.length()-1] - '0';
            temp.pop_back();
            arr[pos] = temp;
            count++;
            temp.clear();
        }
        else
        {
            temp += s[i];
        }
        if(s[i+1] == '\0')
        {
            int pos = temp[temp.length()-1] - '0';
            temp.pop_back();
            arr[pos] = temp;
            count++;
            temp.clear();
        }
        i++;
    }
    for(int k=1; k<count+1 ; k++)
    {
        cout << arr[k] << "  ";
    }
}