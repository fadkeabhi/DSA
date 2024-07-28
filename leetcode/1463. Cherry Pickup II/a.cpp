#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int n, m;
    vector<vector<int>> g;
    vector<vector<vector<int>>> dp;
    int f(int row, int a, int b)
    {
        if (a < 0 || b < 0 || a >= m || b >= m)
        {
            return 0;
        }
        if (dp[row][a][b] != -1)
            return dp[row][a][b];
        if (row == n - 1)
        {
            if (a == b)
            {
                return g[row][a];
            }
            else
            {
                return g[row][a] + g[row][b];
            }
        }

        row++;

        int ans = 0;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                ans = max(ans, f(row, a + i, b + j));
            }
        }

        // vector<int> ans(9, 0);
        // ans[0] = f(row, a, b);
        // ans[1] = f(row, a - 1, b);
        // ans[2] = f(row, a + 1, b);

        // ans[3] = f(row, a, b + 1);
        // ans[4] = f(row, a - 1, b + 1);
        // ans[5] = f(row, a + 1, b + 1);

        // ans[6] = f(row, a, b - 1);
        // ans[7] = f(row, a - 1, b - 1);
        // ans[8] = f(row, a + 1, b - 1);

        // for (int i = 1; i < 9; i++)
        // {
        //     ans[i] = max(ans[i], ans[i - 1]);
        // }

        row--;

        if (a == b)
        {
            dp[row][a][b] = ans + g[row][a];
        }
        else
        {
            dp[row][a][b] = ans + g[row][a] + g[row][b];
        }

        return dp[row][a][b];
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        g = grid;
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return f(0, 0, m - 1);
    }

    // Tab not working some error;
    int tab(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int i = 0; i < m; i++)
        {
            // base case
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                    dp[n - 1][i][j] = grid[n - 1][i];
                else
                    dp[n - 1][i][j] = grid[n - 1][i] + grid[n - 1][j];
            }
        }
        for (int r = n - 2; r > -1; r--)
        {
            for (int a = 0; a < m; a++)
            {
                for (int b = 0; b < m; b++)
                {
                    int maxi = 0;
                    for (int i = -1; i < 2; i++)
                    {
                        for (int j = -1; j < 2; j++)
                        {
                            int ans = 0;
                            if (i == j)
                                ans = grid[r][a];
                            else
                                ans = grid[r][a] + grid[r][b];

                            if(a+i >= 0 && b+j >= 0 && a+i <m && b+j <m){
                                ans += dp[r][a+i][b+j];
                            }
                            else{
                                ans = 0;
                            }
                            maxi = max(maxi, ans);
                        }
                    }
                    dp[r][a][b] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

int main()
{
    vector<vector<vector<int>>> testCases = {
        {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}},
        {{1, 0, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 3, 0}, {2, 0, 9, 0, 0, 0, 0}, {0, 3, 0, 5, 4, 0, 0}, {1, 0, 2, 3, 0, 0, 6}}};
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.cherryPickup(testCase) << endl;
        // cout << s.tab(testCase) << endl;
    }
    return 0;
}