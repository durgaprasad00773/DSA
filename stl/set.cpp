//set is implemented by avl trees
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class person
{
    public:
    int age;
    string name;

    bool operator < (const person &other) const{
        return age < other.age;
    }
};
int main()
{
    set<int, greater<int>> a= {2, 5, 1, 6, 9, 4};
    // for(auto i : a)
    // {
    //     cout << i <<  "  " ;
    // }
    // int x = 5;
    // auto i = a.begin();
    // while(*i != x)
    // {
    //     i++;
    // }
    // a.erase(i);
    // cout << endl;
    // for(auto i : a)
    // {
    //     cout << i <<  "  " ;
    // }


    
    //multiset allows duplicates also

    multiset<int> m = {2, 5, 9, 1, 4, 8, 0, 4, 2, 6, 6};
    for(auto i:m)
    {
        cout << i << "  ";
    }

    m.erase(4);
    cout << endl;

    for(auto i:m)
    {
        cout << i << "  ";
    }




    cout << endl;

    //unordered_set doesn't store in sorting order

    // unordered_set<int> us = {2, 5, 5, 9, 1, 5 , 8};
    // for(auto i: us)
    // {
    //     cout << i << "  ";
    // }
}