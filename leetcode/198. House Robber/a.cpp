#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int n, vector<int>& dp){
        if (n == 0) return nums[0];
        if(dp[n] != -1) return dp[n];
        if(n == 1) return max(nums[0] , nums[1]);
        int rob = nums[n] + f(nums, n-2,dp);
        int notrob = f(nums, n-1, dp);
        return dp[n] = max(rob, notrob);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int n =  nums.size();
        return f(nums, n -1, dp);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
        {1, 3, 1, 3, 100},
        {1,2,3,1},
        {2,7,9,3,1}
    };
    Solution s;
    for (auto& testCase : testCases) {
        cout << s.rob(testCase) << endl;
    }
    return 0;
}