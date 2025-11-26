//pair is implemented by class and objects
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // pair <string, int> p;
    // p = make_pair("pam", 45);
    // cout << "First : " << p.first << endl << "Second : " << p.second << endl;
    // pair <string, int> q("prasad", 99);
    // cout << "first : " << q.first << endl << "Second : " << q.second << endl;
    
    // if(p < q)
    // cout << "p is less than q";
    // else if(q < p)
    // cout << "q is less than p";
    // else
    // cout << "Both are equal";


    vector<pair <string, int> > arr;
    arr.push_back({"Ram", 34});
    arr.push_back({"prasad", 45});

    for (auto &i : arr)
    {
        cout << i.first << "  " << i.second << endl;
    }

}