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

    //BFS

    vector<bool> visited(vertex, 0);
    queue <int> q;
    q.push(0);
    visited[0] = 1;
    vector<int> ans;
    while(!q.empty())
    {
        int index = q.front();
        q.pop();
        ans.push_back(index);
        for(int i=0; i<arr[index].size(); i++)
        {
            if(visited[arr[index][i]] == 0)
            {
                q.push(arr[index][i]);
                visited[arr[index][i]] = 1;
            }
        }   
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }

}