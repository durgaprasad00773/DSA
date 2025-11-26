#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> v(1,1) ;
    cout << "Enter a number : ";
    int n ;
    cin >> n;
    while (n>1)
    {
        int carry = 0;
        int size = v.size();
        int res;
       for(int i=0; i<size; i++)
       {
            res = v[i] * n + carry;
            carry = res / 10;
            v[i] = res%10;
       }
       while(carry)
       {
        v.push_back(carry%10);
        carry/=10;
       }
       n--;
    }
    reverse(v.begin(), v.end());
    for(auto i : v)
    {
        cout << i;
    }
}