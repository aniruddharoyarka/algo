#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];
int distancee[100];

void bfs(int source)
{
    queue<int> q;

    visited[source] = true;
    distancee[source] = 0;

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
                distancee[neighbor] = distancee[node] + 1;
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
        graph[v].push_back(u);      // Undirected graph
    }

    int source;
    cin >> source;

    bfs(source);

    cout << "Shortest distance from node " << source << ":\n";

    for (int i = 0; i < V; i++)
    {
        if (visited[i])
            cout << source << " -> " << i << " = " << distancee[i] << endl;
        else
            cout << source << " -> " << i << " = Not Reachable" << endl;
    }

    return 0;
}

