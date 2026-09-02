#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];
stack<int> st;

void dfs(int node)
{
    visited[node] = true;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }

    // Push after visiting all neighbors
    st.push(node);
}

void topologicalSort(int V)
{
    // Run DFS from every unvisited vertex
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    cout << "Topological Order: ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
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
    }

    printAdjacencyList(V);

    cout << endl;

    topologicalSort(V);

    return 0;
}
