#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r = 3658;
    int d = 9240;
    int count = 0;
    while(r > 0)
    {
        int rem1 = r%10;
        int rem2 = d%10;

        int diff = abs(rem1 - rem2);
        count += min(diff, 10-diff);

        r/=10;
        d/=10;

    }

    cout << count;
}