#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void f(vector<int> &nums, int target, int &ans, int n, int sum)
    {
        if (n == 0)
        {
            if (sum + nums[0] == target)
            {
                ans++;
            }
            if (sum - nums[0] == target)
            {
                ans++;
            }
            return;
        }
        f(nums, target, ans, n - 1, sum + nums[n]);
        f(nums, target, ans, n - 1, sum - nums[n]);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int ans = 0;
        int n = nums.size();
        f(nums, target, ans, n - 1, 0);
        return ans;
    }
};

int main()
{
    vector<pair<vector<int>, int>> testCases = {
        {{1, 1, 1, 1, 1}, 3},
        {{1}, 1},
        {{0, 0, 0, 0, 0, 0, 0, 0, 1}, 1}};
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.findTargetSumWays(testCase.first, testCase.second) << endl;
    }
    return 0;
}