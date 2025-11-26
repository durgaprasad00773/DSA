#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int vertex, edges;
    cout << "Enter vertex and edges : ";
    cin >> vertex >> edges;
    vector< vector<bool> > adjMat(vertex, vector<bool>(vertex, 0));
    int u, v;
    for(int i=0; i<edges; i++)
    {
        cin >> u >> v; 
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    cout << "The representation : " << endl;

    for(auto i : adjMat)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}