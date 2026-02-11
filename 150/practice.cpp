#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ---------- Dijkstra's Algorithm ----------
void dijkstra(vector<vector<int>> &adj, int start, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int minDist = INT_MAX;

        // Find vertex with minimum distance not yet visited
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // All remaining vertices are unreachable
        visited[u] = true;

        // Update distances to adjacent vertices
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !visited[v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "To " << i << " : INF\n";
        else
            cout << "To " << i << " : " << dist[i] << "\n";
    }
}

// ---------- Floyd–Warshall Algorithm ----------
void floydWarshall(vector<vector<int>> &adj, int n) {
    vector<vector<int>> dist = adj;

    // Replace 0 (no edge) with INF except diagonal
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && dist[i][j] == 0)
                dist[i][j] = INT_MAX / 2; // to prevent overflow

    // Core algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cout << "\nAll Pairs Shortest Path Matrix (Floyd–Warshall):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INT_MAX / 2)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

// ---------- Main Function ----------
int main() {
    int n, choice, start;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Single Source Shortest Path (Dijkstra's Algorithm)\n";
        cout << "2. All Pairs Shortest Path (Floyd–Warshall Algorithm)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter starting vertex (0 to " << n - 1 << "): ";
                cin >> start;
                dijkstra(adj, start, n);
                break;
            case 2:
                floydWarshall(adj, n);
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
