#include <bits/stdc++.h>
using namespace std;

// Function 1: Find the length of LCS
int lcs(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

// Function 2: Print the actual LCS
void printLCS(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the same DP table
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Start from the bottom-right of the table
    int i = m;
    int j = n;

    string ans = "";

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            // This character is part of the LCS
            ans += s1[i - 1];

            i--;
            j--;
        }
        else
        {
            // Move in the direction of the larger value
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    // We collected the string backwards
    reverse(ans.begin(), ans.end());

    cout << "Longest Common Subsequence: " << ans << endl;
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << "Length: " << lcs(s1, s2) << endl;

    printLCS(s1, s2);

    return 0;
}
