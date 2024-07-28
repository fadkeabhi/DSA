#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int *arr, int n, int sum, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            if (sum == 0)
                return 1;
            return (arr[0] == sum);
        }
        if (dp[n][sum] != -1)
            return dp[n][sum];

        int notTake = f(arr, n - 1, sum, dp);
        int take = 0;
        if (sum >= arr[n])
            take = f(arr, n - 1, sum - arr[n], dp);

        return dp[n][sum] = notTake + take;
    }

    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(arr, n - 1, sum, dp);
    }

    int tab(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        // Initialize the first row based on the first element of the array
        if (arr[0] <= sum)
        {
            dp[0][arr[0]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (j >= arr[i])
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = notTake + take;
            }
        }
        return dp[n - 1][sum];
    }
};

int main()
{
    int t = 3; // Number of test cases

    int n[3] = {6, 5, 10};
    int arr[3][10] = {{5, 2, 3, 10, 6, 8}, {2, 5, 1, 4, 3}, {9, 7, 0, 3, 9, 8, 6, 5, 7, 6}};
    int sum[3] = {10, 10, 31};
    int expected[3] = {3, 3, 40};

    for (int i = 0; i < t; i++)
    {
        Solution ob;
        int result = ob.perfectSum(arr[i], n[i], sum[i]);
        cout << "Test Case " << i + 1 << ": ";
        if (result == expected[i])
        {
            cout << "Passed" << endl;
        }
        else
        {
            cout << "Failed! Expected " << expected[i] << " but got " << result << endl;
        }
        result = ob.tab(arr[i], n[i], sum[i]);
        cout << "Test Case " << i + 1 << ": ";
        if (result == expected[i])
        {
            cout << "Passed" << endl;
        }
        else
        {
            cout << "Failed! Expected " << expected[i] << " but got " << result << endl;
        }
    }
    return 0;
}
