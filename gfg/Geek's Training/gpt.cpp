
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int f(vector<vector<int>>& points, int n, int last, vector<vector<int>>& dp) {
        if (dp[n][last] != -1) return dp[n][last];

        if (n == 0) {
            int max_points = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    max_points = max(max_points, points[0][i]);
                }
            }
            return dp[n][last] = max_points;
        }

        int max_points = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                int point = points[n][i] + f(points, n - 1, i, dp);
                max_points = max(max_points, point);
            }
        }

        return dp[n][last] = max_points;
    }

    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(points, n - 1, 3, dp);
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {3, {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}}},
        {10, {{8, 7, 3}, {10, 6, 3}, {1, 1, 4}, {10, 2, 9}, {2, 10, 6}, {4, 3, 6}, {3, 6, 9}, {7, 8, 8}, {3, 3, 10}, {5, 2, 10}}}
    };

    Solution s;
    for (auto& testCase : testCases) {
        int n = testCase.first;
        vector<vector<int>> points = testCase.second;
        cout << s.maximumPoints(points, n) << endl; 
    }
    return 0;
}