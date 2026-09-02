#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];

void dfs(int node)
{
    //cout << node << endl;
    visited[node] = true;

    for(int neighbor : graph[node])
    {
        if(!visited[neighbor])
        {
            dfs(neighbor);
        }
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

    int components = 0;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            components++;
        }
    }

    cout << components << endl;

    return 0;
}

