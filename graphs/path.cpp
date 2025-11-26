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
    vector<int> parent(vertex, -1);

    q.push(0);
    parent[0] = -2;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int j=0; j<arr[node].size(); j++)
        {
            if(parent[arr[node][j]] == -1)
            {
                q.push(arr[node][j]);
                parent[arr[node][j]] = node;
            }
        }
    }
    int dest = 6;
    vector<int> ans;
    ans.push_back(dest);
    while(parent[dest] != -2)
    {
        ans.push_back(parent[dest]);
        dest = parent[dest];
    }

    for(auto i : ans)
    cout << i << "  ";


}