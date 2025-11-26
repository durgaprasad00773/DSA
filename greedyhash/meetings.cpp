#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    //sort the end timings

    //use pairs

    int count = 1;
    int last = end[0];
    for(int i=1; i<start.size(); i++)
    {
        if(start[i] > last)
        {
            count++;
            last = end[i];
        }
    }

    cout << count;
}