#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(int *price, int l, int n)
    {

        if (n == 0)
        {
            return l * price[0];
        }

        int notTake = f(price, l, n - 1);
        int take = 0;
        if (n + 1 <= l)
        {
            take = price[n] + f(price, l - (n + 1), n);
        }
        return max(take, notTake);
    }

    int cutRod(int price[], int n)
    {
        return f(price, n, n - 1);
    }

    int tab(int price[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Initialize the first row
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i * price[0];
        }

        // Fill the DP table
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (i + 1 <= j)
                {
                    take = price[i] + dp[i][j - (i + 1)];
                }
                dp[i][j] = max(take, notTake);
            }
        }


        return dp[n - 1][n];
    }
};

int main()
{
    int t = 2;
    int n[] = {8, 8};
    int a[][8] = {{1, 5, 8, 9, 10, 17, 17, 20}, {3, 5, 8, 9, 10, 17, 17, 20}};
    Solution ob;
    for (int i = 0; i < t; ++i)
    {
        cout << ob.cutRod(a[i], n[i]) << endl;
        cout << ob.tab(a[i], n[i]) << endl;
    }
    return 0;
}