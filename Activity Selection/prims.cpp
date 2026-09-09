#include <iostream>
#include <climits>
using namespace std;

int minKey(int key[], bool mstSet[], int V)
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[][5], int V)
{
    cout << "Edge\tWeight\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[parent[i]][i] << endl;
    }
}

void primMST(int graph[][5], int V)
{
    int parent[5];
    int key[5];
    bool mstSet[5];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                mstSet[v] == false &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main()
{
    int V = 5;

    int graph[5][5] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, V);

    return 0;
}

