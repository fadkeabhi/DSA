bool tab(vector<int> arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Initialize the dp table for base case
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    // Check if first element is within the target range
    if (arr[0] <= target)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool notTaken = dp[i - 1][j];

            bool taken = false;
            if (arr[i] <= j)
                taken = dp[i - 1][j - arr[i]];

            dp[i][j] = taken || notTaken;
        }
    }

    return dp[n - 1][target];
}