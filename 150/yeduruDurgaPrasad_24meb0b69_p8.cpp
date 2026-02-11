#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Structure for Kruskal's algorithm
struct Edge {
    int u, v, w;
};

// Function to print selected edges
void printEdge(int u, int v) {
    cout << "(" << u << ", " << v << ")\n";
}

//DFS Traversal
void DFS(vector<vector<int>> &adj, int start, int n) {
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);
    visited[start] = true;

    cout << "Edges in DFS Traversal:\n";

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v = n - 1; v >= 0; v--) { // reverse order for consistent traversal
            if (adj[u][v] != 0 && !visited[v]) {
                printEdge(u, v);
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

//BFS Traversal
void BFS(vector<vector<int>> &adj, int start, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "Edges in BFS Traversal:\n";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !visited[v]) {
                printEdge(u, v);
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

//Kruskal's Algorithm
int findParent(int u, vector<int> &parent) {
    if (parent[u] == u)
        return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void kruskalMST(vector<vector<int>> &adj, int n) {
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] != 0) {
                edges.push_back({i, j, adj[i][j]});
            }
        }
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;
    cout << "Edges in MST (Kruskal's Algorithm):\n";
    for (auto &e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);
        if (pu != pv) {
            printEdge(e.u, e.v);
            cost += e.w;
            unionSet(pu, pv, parent, rank);
        }
    }
    cout << "Total cost of MST: " << cost << "\n";
}

// ---------------- Prim's Algorithm ----------------
void primMST(vector<vector<int>> &adj, int start, int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    key[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    int cost = 0;
    cout << "Edges in MST (Prim's Algorithm):\n";
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printEdge(parent[i], i);
            cost += adj[i][parent[i]];
        }
    }
    cout << "Total cost of MST: " << cost << "\n";
}

int main() {
    int n, choice, start;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Depth First Search (DFS)\n";
        cout << "2. Breadth First Search (BFS)\n";
        cout << "3. Minimum Spanning Tree (Kruskal's Algorithm)\n";
        cout << "4. Minimum Spanning Tree (Prim's Algorithm)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter starting vertex (0 to " << n - 1 << "): ";
                cin >> start;
                DFS(adj, start, n);
                break;
            case 2:
                cout << "Enter starting vertex (0 to " << n - 1 << "): ";
                cin >> start;
                BFS(adj, start, n);
                break;
            case 3:
                kruskalMST(adj, n);
                break;
            case 4:
                cout << "Enter starting vertex (0 to " << n - 1 << "): ";
                cin >> start;
                primMST(adj, start, n);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
