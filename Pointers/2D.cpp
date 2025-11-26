#include <iostream>
using namespace std;
int main()
{
    int m;
    int n;
    cin >> m >> n;
    int ** ptr = new int*[m];
    for(int i=0; i<n; i++)
    {
        ptr[i] = new int[n];
    }
    // assigning values to the 2-D array
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> ptr[i][j];
        }
    }
    // printing values from 2-D array
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << ptr[i][j] << "  "; 
        }
        cout << "\n";
    }
    // deleting allocated memory
    for(int i=0; i<m; i++)
    {
        delete[] ptr[i];
    }
    delete ptr;
}