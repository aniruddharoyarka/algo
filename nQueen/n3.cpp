#include <bits/stdc++.h>
using namespace std;

int x[1000];

bool place(int k, int i)
{
    for(int j = 1; j <= k-1; j++)
    {
        // Same column
        if(i == x[j])
        {
            return false;
        }

        // Left diagonal (\) is NOT allowed
        if(x[j] - i == k - j)
        {
            return false;
        }

        // Right diagonal (/) is permitted,
        // so we don't check it
    }

    return true;
}

bool NQueens(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                return true;   // one valid arrangement found
            }
            else
            {
                if(NQueens(k + 1, n))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    if(NQueens(1, n))
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(x[i] == j)
                    cout << "P";
                else
                    cout << ".";
            }

            cout << endl;
        }
    }

    return 0;
}
