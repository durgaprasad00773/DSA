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
    // map <int, int> m = {
    //     {1, 23}, {3, 34}, {0, 43}, {5, 89}, {0, 44}
    // };

    // m.erase(0);
    // for(auto i : m)
    // {
    //     cout << i.first << "  " << i.second << endl;
    // }

    //multimap

    // multimap<int , int> mm = 
    //     {
    //         {1, 23}, {3, 34}, {0, 43}, {5, 89}, {0, 44}, {1, 45}, {3, 22}
    // };

    // for(auto i : mm)
    // {
    //     cout << i.first << "  " << i.second << endl;
    // }
    
    //unordered_map

    unordered_map<int , int> um = 
        {
            {1, 23}, {3, 34}, {0, 43}, {5, 89}, {0, 44}, {1, 45}, {3, 22}
    };

    for(auto i : um)
    {
        cout << i.first << "  " << i.second << endl;
    }



    
}