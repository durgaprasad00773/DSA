#include <iostream>
using namespace std;
int main()
{   
    string check = "abcdefghijklmnopqrstuvwxyz";
    string s = "abcdefg hijkl mnopqrstu vweexyz";
    int count = 0;
    for(int i=0; i<check.size(); i++)
    {
        for (int j=0; j<s.size(); j++)
        {
            if (check[i] == s[j])
            {
                count++;
            }

        }
    }
    if(count == 26)
    {
        cout << "It is a pangram";
    }
    else{
        cout << "It is not a pangram";
    }
}