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

/////////////////////////////////////////////////////////


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

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
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

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
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

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

//qua

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    // Input graph (Undirected)
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source = 1;
    int destination = n;

    // dist[node][0] = coupon not used
    // dist[node][1] = coupon already used
    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    vector<vector<bool>> visited(n + 1, vector<bool>(2, false));

    dist[source][0] = 0;

    // There are 2*n states
    for (int cnt = 1; cnt <= 2 * n; cnt++)
    {
        int u = -1;
        int state = -1;

        // Extract minimum among all states
        for (int i = 1; i <= n; i++)
        {
            for (int s = 0; s <= 1; s++)
            {
                if (!visited[i][s] &&
                    (u == -1 || dist[i][s] < dist[u][state]))
                {
                    u = i;
                    state = s;
                }
            }
        }

        if (u == -1 || dist[u][state] == INF)
            break;

        visited[u][state] = true;

        // Relax edges
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            // Travel normally
            if (!visited[v][state] &&
                dist[u][state] + w < dist[v][state])
            {
                dist[v][state] = dist[u][state] + w;
            }

            // Use coupon (only if not used yet)
            if (state == 0)
            {
                if (!visited[v][1] &&
                    dist[u][0] + w / 2 < dist[v][1])
                {
                    dist[v][1] = dist[u][0] + w / 2;
                }
            }
        }
    }

    cout << min(dist[destination][0], dist[destination][1]) << endl;

    return 0;
}

//b

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    vector<int> dist(n, INF);
    dist[src] = 0;

    // Relax edges exactly (k+1) times
    for (int i = 0; i <= k; i++)
    {
        vector<int> temp = dist;

        for (auto edge : edges)
        {
            if (dist[edge.u] == INF)
                continue;

            if (dist[edge.u] + edge.w < temp[edge.v])
            {
                temp[edge.v] = dist[edge.u] + edge.w;
            }
        }

        dist = temp;
    }

    if (dist[dst] == INF)
        cout << -1 << endl;
    else
        cout << dist[dst] << endl;

    return 0;
}


