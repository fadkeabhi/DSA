#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(n, INT16_MAX);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            int temp = dp[0];
            dp[0] = dp[0] + triangle[i][0];
            for (int j = 1; j <= i; j++)
            {
                int newVal = min(dp[j], temp) + triangle[i][j];
                temp = dp[j];
                dp[j] = newVal;
            }
            // for (int i = 0; i < n; i++)
            // {
            //     cout<<dp[i]<<" ";
            // }
            // cout<<endl;
        }
        int min = dp[0];
        for (int i = 1; i < n; i++)
        {
            if (dp[i] < min)
            {
                min = dp[i];
            }
        }
        return min;
    }
};

int main()
{
    vector<vector<vector<int>>> testCases = {
        {{-7},{-2,1},{-5,-5,9},{-4,-5,4,4},{-6,-6,2,-1,-5},{3,7,8,-3,7,-9},{-9,-1,-9,6,9,0,7},{-7,0,-6,-8,7,1,-4,9},{-3,2,-6,-9,-7,-6,-9,4,0},{-8,-6,-3,-9,-2,-6,7,-5,0,7},{-9,-1,-2,4,-2,4,4,-1,2,-5,5},{1,1,-6,1,-2,-4,4,-2,6,-6,0,6},{-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1}},
        {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}},
        {{-10}},
        {{1}},
        {{-1}, {2, 3}, {1, -1, -3}}};
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.minimumTotal(testCase) << endl;
    }
    return 0;
}