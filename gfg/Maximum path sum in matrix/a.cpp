#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < N; i++)
        {
            dp[i] = Matrix[0][i];
        }
        for (int i = 1; i < N; i++)
        {
            vector<int> next(N + 1, 0);
            next[0] = max(dp[0], dp[1]) + Matrix[i][0];
            for (int j = 0; j < N; j++)
            {
                next[j] = max(max(dp[j], dp[j - 1]), dp[j + 1]) + Matrix[i][j];
            }
            dp = next;
        }
        for (int i = 1; i < N; i++)
        {
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp[N-1];
    }
};

int main()
{
    vector<pair<int, vector<vector<int>>>> testCases = {
        {2, {{348, 391}, {618, 193}}},
        {2, {{2, 2}, {2, 2}}},
        {4, {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}}}};
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.maximumPath(testCase.first, testCase.second) << endl;
    }
    return 0;
}