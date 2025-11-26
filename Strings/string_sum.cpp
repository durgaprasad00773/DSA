#include <iostream>
using namespace std;
string add(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    int sum=0;
    int carry=0; 
    string ans;
    if(n2 > n1)
    {
        int temp = n1;
        n1 = n2;
        n2 = temp;
        string kemp = str1;
        str1 = str2;
        str2 = kemp;
    }
    while(n2-1 >= 0)
    {
        sum = (str1[n1-1] - '0') + (str2[n2-1] - '0') + carry;
        char c = sum%10 + '0';
        carry = sum/10;
        ans = ans + c;
        sum=0;
        n2--;;
        n1--;
    }
    while(n1 > 0)
    {
        sum = str1[n1-1] - '0'  + carry;
        carry = sum/10;
        char c = sum % 10 + '0';
        sum = 0;
        ans = ans + c;
        if(n1==0 )
        {
            ans +=  carry+'0';
        }
        n1--;
    }
    int start = 0; 
    int end = ans.length() - 1;
    while(start < end)
    {
        swap(ans[start], ans[end]);
        start++;
        end--;
    }
    return ans+'0';
}
int main()
{
    string str1 = "123456";
    string str2 = "789";
    cout << add(str1,str2);
}