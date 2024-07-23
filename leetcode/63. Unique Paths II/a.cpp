#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int fmem(int m, int n, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
    {
        
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == m - 1 && j == n - 1)
        {
            dp[i][j] = 1;
            return 1;
        }
        if (grid[i][j] == 1)
        {
            dp[i][j] = 0;
            return 0;
        }
        if (i >= m || j >= n)
        {
            dp[i][j] = 0;
            return 0;
        }
        int d = fmem(m, n, i + 1, j, dp, grid);
        int r = fmem(m, n, i, j + 1, dp, grid);
        dp[i][j] = d + r;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int row = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        if(obstacleGrid[row-1][cols-1] == 1) return 0;
        if(obstacleGrid[0][0] == 1) return 0;

        vector<int> dp(cols+1, 0);
        dp[0] = 1;
        for(int i=0; i<row; i++){
            if(obstacleGrid[i][0] == 1) dp[0] = 0;
            for(int j=1; j<cols; j++){
                dp[j] = dp[j] + dp[j-1];
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
            }
        }

        return dp[cols-1];

        
    }
};

int main()
{
    vector<vector<vector<int>>> testCases = {
        {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
        {{0, 1}, {0, 0}},
        {{0, 0}, {0, 1}},
        {{0, 0}, {1, 0}},
        {{1}},
        {{0}}};
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.uniquePathsWithObstacles(testCase) << endl;
    }
    return 0;
}