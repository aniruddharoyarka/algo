#include <bits/stdc++.h>
using namespace std;

#define edge pair<int, int>

// Graph edges
vector<pair<int, edge>> G;

// Minimum Spanning Tree
vector<pair<int, edge>> T;

// Parent array
vector<int> parent(46);

// Add an edge
void Add_edge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}

// Find representative
int find_set(int i) {

    if (i == parent[i])
        return i;

    return find_set(parent[i]);
}

// Union two sets
void uunion(int u, int v) {
    parent[u] = parent[v];
}

// Kruskal's Algorithm
void kruskal(int V) {

    int uRep, vRep;

    // Sort edges according to weight
    sort(G.begin(), G.end());

    // Process all edges
    for (int i = 0; i < G.size(); i++) {

        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);

        // If different sets, add edge to MST
        if (uRep != vRep) {

            T.push_back(G[i]);

            uunion(uRep, vRep);
        }

        // MST contains V-1 edges
        if (T.size() == V - 1)
            break;
    }
}

// Print MST
void print() {

    int total_weight = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 0; i < T.size(); i++) {

        cout << T[i].second.first
             << " - "
             << T[i].second.second
             << " : "
             << T[i].first
             << endl;

        total_weight += T[i].first;
    }

    cout << "\nTotal weight = "
         << total_weight
         << endl;

    cout << "Total edges = "
         << T.size()
         << endl;
}

int main() {

    // ==========================================
    // Sparse Graph
    // ==========================================

    const int V = 45;
    const int E = 175;

    // Fixed seed
    // This makes the same graph every time.
    mt19937 rng(2026);

    // Random weight: 1 to 100
    uniform_int_distribution<int> weightDist(1, 100);

    // Random node: 1 to 45
    uniform_int_distribution<int> nodeDist(1, V);

    // Store already-used edges
    set<pair<int, int>> used;

    // ==========================================
    // Make sure the graph is connected
    // ==========================================

    // Create a chain:
    // 1-2, 2-3, 3-4, ..., 44-45

    for (int i = 1; i < V; i++) {

        int w = weightDist(rng);

        Add_edge(i, i + 1, w);

        used.insert({i, i + 1});
    }

    // ==========================================
    // Add random edges
    // until total edges = 175
    // ==========================================

    while ((int)G.size() < E) {

        int u = nodeDist(rng);
        int v = nodeDist(rng);

        // No self-loop
        if (u == v)
            continue;

        // Keep smaller node first
        if (u > v)
            swap(u, v);

        // No duplicate edge
        if (used.count({u, v}))
            continue;

        // Mark edge as used
        used.insert({u, v});

        // Generate random weight
        int w = weightDist(rng);

        // Add edge
        Add_edge(u, v, w);
    }

    // ==========================================
    // Initialize parent
    // ==========================================

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    // ==========================================
    // Display Graph Information
    // ==========================================

    cout << "Sparse Graph" << endl;
    cout << "Nodes = " << V << endl;
    cout << "Edges = " << G.size() << endl;

    // ==========================================
    // Run Kruskal
    // ==========================================

    kruskal(V);

    // ==========================================
    // Print MST
    // ==========================================

    print();

    return 0;
}
