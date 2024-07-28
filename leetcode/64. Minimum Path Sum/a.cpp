#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp)
    {
        if (n < 0 || m < 0)
            return INT32_MAX;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (n == 0 && m == 0)
        {
            return grid[0][0];
        }
        int l = f(grid, n, m - 1, dp);
        int u = f(grid, n - 1, m, dp);
        dp[n][m] = grid[n][m] + min(l, u);
        return dp[n][m];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(grid, n - 1, m - 1, dp);
    }

    int tab(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT16_MAX));
        dp[0][0] = grid[0][0];
        // first row
        for (int i = 1; i < m; i++)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        // first col
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main()
{
    vector<vector<vector<int>>> testCases = {
        {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
        {{1, 2, 3}, {4, 5, 6}},
        {{0}},
        {{1}},
    };
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.minPathSum(testCase) << endl;
        cout << s.tab(testCase) << endl;
    }
    return 0;
}