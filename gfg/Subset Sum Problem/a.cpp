#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        // If the target sum is 0, we have found a subset
        if (target == 0)
            return true;

        // If we have reached the first element in 'arr'
        if (ind == 0)
            return arr[0] == target;

        // If the result for this subproblem has already been computed, return it
        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Try not taking the current element into the subset
        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

        // Try taking the current element into the subset if it doesn't exceed the target
        bool taken = false;
        if (arr[ind] <= target)
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

        // Store the result in the dp array to avoid recomputation
        return dp[ind][target] = notTaken || taken;
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return subsetSumUtil(n - 1, sum, arr, dp);
    }

    bool tab(vector<int> arr, int target)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (arr[0] <= target)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool notTaken = dp[i - 1][j];

                bool taken = false;
                if (arr[i] <= j)
                    taken = dp[i - 1][j - arr[i]];

                dp[i][j] = taken | notTaken;
            }
        }

        return dp[n - 1][target];
    }
};

int main()
{
    vector<pair<vector<int>, int>> testCases = {
        {{3, 34, 4, 12, 5, 2}, 9},
        {{3, 34, 4, 12, 5, 2}, 30},
        {{1, 5, 11, 5}, 11}};
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.isSubsetSum(testCase.first, testCase.second) << endl;
        cout << s.tab(testCase.first, testCase.second) << endl;
    }
    return 0;
}