#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
    int vertex, edges;
    cout << "Enter vertex and edges: ";
    cin >> vertex >> edges;

    vector<vector<pair<int, int>>> arr(vertex);  // Adjacency list

    int u, v, w;
    cout << "Enter edges (u v w): " << endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        arr[u].push_back({w, v});  // Edge from u -> v with weight w
    }

    // Dijkstra's Algorithm
    vector<bool> visited(vertex, false);
    vector<int> dist(vertex, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node 0
    dist[0] = 0;
    pq.push({0, 0}); // (distance, node)

    while (!pq.empty())
    {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        for(int j=0; j<arr[node].size(); j++)
        {
            int neighbour = arr[node][j].second;
            int weight = arr[node][j].first;

            if(!visited[neighbour] && dist[node]+weight < dist[neighbour])
            {
                dist[neighbour] = dist[node]+weight;
                pq.push({dist[neighbour], neighbour});
            }

        }
    }

    // Print shortest distances from node 0
    cout << "Shortest distances from node 0: ";
    for (int i = 0; i < vertex; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
