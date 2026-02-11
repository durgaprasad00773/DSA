#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w;
    cout << "Enter the weight of the melon : ";
    cin >> w;

    if(w > 2 && w%2==0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}