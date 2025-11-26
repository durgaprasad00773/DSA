#include <iostream>
using namespace std;
int main()
{
    int l,m,n;
    cin >> l >> m >> n;
    int ***ptr = new int**[l];
    for(int i=0; i<l; i++)
    {
        ptr[i] = new int*[m];
        for(int j=0; j<m; j++)
        {
            ptr[i][j] = new int[n];
        }
    }
    //assigning values to 3D array
    for(int i=0; i<l; i++)
    {
        for (int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                cin >> ptr[i][j][k];
            }
        }
    }
    //printing vlues in 3D array
    for(int i=0; i<l; i++)
    {
        for (int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                cout << ptr[i][j][k] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }

    //deleting allocated memory

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<m; j++)
        {
            delete ptr[i][j];
        }
    }
    for(int i=0; i<l; i++)
    {
        delete ptr[i];
    }
    delete ptr;
}