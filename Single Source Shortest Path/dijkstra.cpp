#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    // Input graph
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        //adj[v].push_back({u, w}); // Remove for directed graph
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    dist[source] = 0;

    // Run n times
    for (int i = 1; i <= n; i++)
    {
        // EXTRACT-MIN(Q)
        int u = -1;

        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        if (u == -1)
            break;

        // S = S U {u}
        visited[u] = true;

        // RELAX all adjacent vertices
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (!visited[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "Shortest distances:\n";
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }

    return 0;
}
