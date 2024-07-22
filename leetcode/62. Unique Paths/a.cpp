#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(int m, int n, int i, int j)
    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        int d = f(m, n, i + 1, j);
        int r = f(m, n, i, j + 1);
        return d + r;
    }

    int fmem(int m, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == m - 1 && j == n - 1)
        {
            dp[i][j] = 1;
            return 1;
        }
        if (i >= m || j >= n)
        {
            dp[i][j] = 0;
            return 0;
        }
        int d = fmem(m, n, i + 1, j, dp);
        int r = fmem(m, n, i, j + 1, dp);
        dp[i][j] = d + r;
        return dp[i][j];
    }

    int uniquePaths(int m, int n)
    {
        if(m==1 || n == 1) return 1;
        // return f(m,n,0,0);
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return fmem(m, n, 0, 0, dp);
    }

    int tab(int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int i = 0; i<m; i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i<n; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int space(int m, int n){
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};

int main()
{
    vector<pair<int, int>> testCases = {
        {2, 2},
        {3, 2},
        {23, 12},
        {1, 1},
        {10, 10}};
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.uniquePaths(testCase.first, testCase.second) << endl;
        cout << s.tab(testCase.first, testCase.second) << endl;
        cout << s.space(testCase.first, testCase.second) << endl;
    }
    return 0;
}