#include <bits/stdc++.h>
using namespace std;

int minMultRec(vector<int> &arr, int i, int j,
               vector<vector<int>> &memo,
               vector<vector<int>> &split)
{
    if (i + 1 == j)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    int res = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {
        int curr = minMultRec(arr, i, k, memo, split)
                 + minMultRec(arr, k, j, memo, split)
                 + arr[i] * arr[k] * arr[j];

        if (curr < res)
        {
            res = curr;
            split[i][j] = k;
        }
    }

    memo[i][j] = res;

    return res;
}


int matrixMultiplication(vector<int> &arr,
                         vector<vector<int>> &split)
{
    int n = arr.size();

    vector<vector<int>> memo(n, vector<int>(n, -1));

    return minMultRec(arr, 0, n - 1, memo, split);
}


// Separate function to print multiplication order
void printOrder(vector<vector<int>> &split, int i, int j)
{
    // Only one matrix
    if (i + 1 == j)
    {
        cout << char('A' + i);
        return;
    }

    int k = split[i][j];

    cout << "(";

    printOrder(split, i, k);

    cout << " x ";

    printOrder(split, k, j);

    cout << ")";
}


int main()
{
    vector<int> arr = {2, 1, 3, 4};

    int n = arr.size();

    vector<vector<int>> split(n, vector<int>(n, -1));

    int res = matrixMultiplication(arr, split);

    cout << "Minimum multiplication cost: " << res << endl;

    cout << "Multiplication order: ";
    printOrder(split, 0, n - 1);

    cout << endl;

    return 0;
}
