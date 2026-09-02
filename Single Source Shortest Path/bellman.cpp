#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;

    // Store all edges
    vector<tuple<int, int, int>> edges;

    // Input graph
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
        // edges.push_back({v, u, w}); // Uncomment for undirected graph
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, INF);

    dist[source] = 0;

    // Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u, v, w;
            tie(u, v, w) = edge;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    bool negativeCycle = false;

    for (auto edge : edges)
    {
        int u, v, w;
        tie(u, v, w) = edge;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        cout << "Negative Weight Cycle Detected\n";
    }
    else
    {
        cout << "Shortest distances:\n";

        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INF)
                cout << i << " : INF\n";
            else
                cout << i << " : " << dist[i] << "\n";
        }
    }

    return 0;
}
