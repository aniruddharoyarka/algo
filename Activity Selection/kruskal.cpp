#include <bits/stdc++.h>
using namespace std;

int parent[100], rnk[100];

int findParent(int u)
{
    if (parent[u] != u)
        parent[u] = findParent(parent[u]);

    return parent[u];
}

void mergeSets(int x, int y)
{
    x = findParent(x);
    y = findParent(y);

    if (rnk[x] > rnk[y])
        parent[y] = x;
    else
        parent[x] = y;

    if (rnk[x] == rnk[y])
        rnk[y]++;
}

void kruskal(int edges[][3], int V, int E)
{
    int mstWeight = 0;
    int edgeCount = 0;

    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                swap(edges[j][0], edges[j + 1][0]);
                swap(edges[j][1], edges[j + 1][1]);
                swap(edges[j][2], edges[j + 1][2]);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }

    cout << "Edges of MST are:\n";

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int setU = findParent(u);
        int setV = findParent(v);

        if (setU != setV)
        {
            cout << u << " - " << v << " = " << w << endl;

            mstWeight += w;
            edgeCount++;

            mergeSets(setU, setV);

            if (edgeCount == V - 1)
                break;
        }
    }

    cout << "\nWeight of MST is " << mstWeight << endl;
}

int main()
{
    int V = 9;
    int E = 14;

    int edges[14][3] =
    {
        {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 8, 2},
        {2, 5, 4},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 6},
        {7, 8, 7}
    };

    kruskal(edges, V, E);

    return 0;
}
