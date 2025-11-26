#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("zoom.txt");
    int a = fin.get();
    int arr[7];
    int j = 0;
    while(!fin.eof())
    {
       arr[j] = a;
       a = fin.get();
       j++;
    }
    for(auto i : arr)
    {
        cout << i << " ";
    }
    
}
