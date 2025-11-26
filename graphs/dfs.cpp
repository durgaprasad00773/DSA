#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//creating a DFS traversal

void dfs(int node, vector<int> arr[], vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for(int j=0; j<arr[node].size(); j++)
    {
        if(visited[arr[node][j]] == 0)
        {
            dfs(arr[node][j], arr, visited, ans);
        }
    }
}

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

    // for(int i=0; i<vertex; i++)
    // {
    //     cout << i << " -> ";
    //     for(int j=0; j<arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    vector<bool> visited(vertex, 0);
    vector<int> ans;
    dfs(0, arr, visited, ans);
    for(auto i: ans)
    {
        cout << i << "  ";
    }

}