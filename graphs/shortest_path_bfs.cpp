#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int vertex, edges;
    cout << "Enter vertex and edges : ";
    cin >> vertex  >> edges;
    vector <int> arr[9];
    int u, v;

    //making a graph

    for(int i=0; i<edges; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    //printing out the graph

    for(int i=0; i<vertex; i++)
    {
        cout << i << " -> ";
        for(int j=0; j<arr[i].size(); j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    queue<int> q;
    vector<int> path(vertex, -1);

    q.push(0);
    path[0] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int j=0; j<arr[node].size(); j++)
        {
            if(path[arr[node][j]] == -1)
            {
                q.push(arr[node][j]);
                path[arr[node][j]] = 1 + path[node];
            }
        }
    }

    for(auto i : path)
    {
        cout << i << "  ";
    }

}