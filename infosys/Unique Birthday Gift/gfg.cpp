#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Function to count the number of valid arrays of length
// 'k'
int countValidArrays(int n, int k)
{
    // dp[i][j] represents the number of valid arrays of
    // length i ending with element j
    vector<vector<int> > dp(k + 1, vector<int>(n + 1, 0));

    // Base case: There are 'n' arrays of length 1, each
    // ending with a different number from 1 to 'n'
    for (int j = 1; j <= n; j++) {
        dp[1][j] = 1;
    }

    // Fill the dp array
    for (int len = 2; len <= k; len++) {
        for (int end = 1; end <= n; end++) {
            for (int prev = 1; prev <= n; prev++) {
                if (end % prev == 0) {
                    dp[len][end] += dp[len - 1][prev];
                }
            }
        }
    }

    // Sum up all valid arrays of length 'k'
    int result = 0;
    for (int j = 1; j <= n; j++) {
        result += dp[k][j];
    }

    return result;
}
void f(int n, int left, int prev, long long int &ans)
    {
        if (left == 0)
            return;
        if (left == 1)
        {
            int i = prev;
            ans += n/prev;
            return;
        }
        int i = prev;
        while (true)
        {
            if (i > n)
                return;
            f(n, left-1, i, ans);
            i += prev;
        }
    }

    long long int mySolution(int n, int k)
    {
        long long int ans = 0;
        f(n, k, 1, ans);
        return ans;
    }


int main() {
    vector<pair<int, int>> testCases = {
        {2, 1},
        {2, 2},
        {3, 2},
        {14000, 70},
    };

    for (auto& testCase : testCases) {
        int n = testCase.first;
        int k = testCase.second;

        auto start = chrono::high_resolution_clock::now();
        int result1 = countValidArrays(n, k);
        auto end = chrono::high_resolution_clock::now();

        auto elapsed1 = chrono::duration_cast<chrono::nanoseconds>(end - start);

        start = chrono::high_resolution_clock::now();
        int result2 = mySolution(n, k);
        end = chrono::high_resolution_clock::now();

        auto elapsed2 = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout << "Test case (n=" << n << ", k=" << k << "):\n";
        cout << "Result: " << result1 << "\n";
        cout << "Time: " << elapsed1.count() << " nanosecondsByGFG\n";
        cout << "Time: " << elapsed2.count() << " nanosecondsByMy\n\n";
    }
    return 0;
}