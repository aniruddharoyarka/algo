#include <bits/stdc++.h>
using namespace std;

int x[1000];
int solutions = 0;

bool place(int k, int i)
{
    for(int j = 1; j <= k-1; j++)
    {
        if( i == x[j])
        {
            return false;
        }
        if(x[j] - i == j - k)   // right
        {
            return false;
        }
        if(x[j] - i == k - j)  // left
        {
            return false;
        }


    }

    return true;

}

void NQueens(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(place(k,i))
        {
            x[k] = i;
            if(k == n)
            {
                solutions++;
                for(int j = 1; j <= n; j++)
                {
                    cout << x[j] << " ";
                }
                cout << endl;

            }
            else
            {
                NQueens(k+1,n);
            }

        }

    }

}

int main()
{
    NQueens(1,4);


}
