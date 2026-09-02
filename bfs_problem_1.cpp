#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];
int dist[100];

void bfs(int source)
{
    queue<int> q;

    visited[source] = true;
    dist[source] = 0;

    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);   // Undirected graph
    }

    int source, destination;
    cin >> source >> destination;

    bfs(source);

    if (visited[destination])
        cout << "Shortest Distance from " << source << " to " << destination<< " : " << dist[destination] << endl;
    else
        cout << "No Path Exists" << endl;

    return 0;
}
