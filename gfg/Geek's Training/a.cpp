
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(vector<vector<int>> &points, int n, int last, vector<vector<int>> &dp)
    {
        int curr[4];

        if (dp[n][last] != -1)
            return dp[n][last];

        if (n == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                curr[i] = points[n][i];
            }
        }
        else
        {

            for (int i = 0; i < 3; i++)
            {
                curr[i] = points[n][i] + f(points, n - 1, i, dp);
            }
        }
        curr[last] = 0;

        int max = 0;
        for (int i = 0; i < 3; i++)
        {
            if (curr[i] > max)
                max = curr[i];
        }
        dp[n][last] = max;

        return max;
    }

    int maximumPoints(vector<vector<int>> &points, int n)
    {
        vector<vector<int>> dp(n + 1, {-1, -1, -1, -1});
        return f(points, n - 1, 3, dp);
    }
};

int main()
{
    vector<pair<int, vector<vector<int>>>> testCases = {
        {3, {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}}},
        {10, {{8, 7, 3}, {10, 6, 3}, {1, 1, 4}, {10, 2, 9}, {2, 10, 6}, {4, 3, 6}, {3, 6, 9}, {7, 8, 8}, {3, 3, 10}, {5, 2, 10}}}};

    Solution s;
    for (auto &testCase : testCases)
    {
        int n = testCase.first;
        vector<vector<int>> points = testCase.second;
        cout << s.maximumPoints(points, n) << endl;
    }
    return 0;
}