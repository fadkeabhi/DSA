#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function with memoization
    int f(int* arr, int n, vector<int>& dp) {
        // Base cases
        if (n < 0) return 0;
        if (n == 0) return arr[0];
        
        // Check if result is already computed
        if (dp[n] != -1) return dp[n];
        
        // Pick the current element and solve for n-2
        int pick = arr[n] + f(arr, n - 2, dp);
        // Do not pick the current element and solve for n-1
        int notpick = f(arr, n - 1, dp);
        
        // Return the maximum of both choices
        dp[n] = max(pick, notpick);
        return dp[n];
    }

    int findMaxSum(int* arr, int n) {
        vector<int> dp(n, -1);  // Initialize memoization table
        return f(arr,n-1,dp);
    }
    
    int findMaxSumTabulation(int* arr, int n) {
        vector<int> dp(n, -1);  // Initialize memoization table
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i = 2; i<n; i++){
            int pick = arr[i] + dp[i-2];
            int notpick = dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[n-1];
    }

    int findMaxSumSpace(int* arr, int n) {
        int p2 = arr[0];
        int p1 = max(arr[0], arr[1]);
        int curr;
        for(int i = 2; i<n; i++){
            int pick = arr[i] + p2;
            int notpick = p1;
            curr = max(pick, notpick);
            p2 = p1;
            p1 = curr;

        }
        return p1;
    }
};

// Driver code
int main() {
    Solution solution;
    int arr[] = {1000, 2000, 3000, 1000, 4000, 5000, 1000, 6000, 7000, 8000, 9000, 10000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solution.findMaxSum(arr, n) << endl;  // Output: 33000
    cout << solution.findMaxSumTabulation(arr, n) << endl;  // Output: 33000
    cout << solution.findMaxSumSpace(arr, n) << endl;  // Output: 33000
    return 0;
}
