#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];

void bfs(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void printAdjacencyList(int V)
{
    cout << "Adjacency List:\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        for (int neighbor : graph[i])
        {
            cout << neighbor << " ";
        }

        cout << endl;
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
        // graph[v].push_back(u);
    }

    printAdjacencyList(V);

    cout << "\nBFS: ";

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }

    return 0;
}
