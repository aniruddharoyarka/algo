#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];

void dfs(int node)
{
    cout << node << " ";
    visited[node] = true;

    for(int neighbor : graph[node])
    {
        if(!visited[neighbor])
        {
            dfs(neighbor);
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

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        //graph[v].push_back(u);
    }

    printAdjacencyList(V);

    cout << "DFS: ";

    for(int i = 0; i < V; i++)
    {
        if(!visited[i]) {
            dfs(i);
        }
    }

    return 0;
}



