//list is implemented by doubly linked lists
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l= {2, 3, 4, 5, 6};

    // for(auto it =l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << "  ";
    // }

    for(auto i = l.rbegin() ; i!= l.rend(); i++)
    {
        cout << *i << "  ";
    }

}