#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

const int MOD = 10000;

class Solution
{
public:
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

    long long int uniqueArrays(int n, int k)
    {
        long long int ans = 0;
        f(n, k, 1, ans);
        return ans;
    }
};

int main() {
    vector<pair<int, int>> testCases = {
        {2, 1},
        {2, 2},
        {3, 2},
        {140, 70},
    };

    Solution sol;
    for (auto& testCase : testCases) {
        int n = testCase.first;
        int k = testCase.second;

        auto start = chrono::high_resolution_clock::now();
        int result = sol.uniqueArrays(n, k);
        auto end = chrono::high_resolution_clock::now();

        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout << "Test case (n=" << n << ", k=" << k << "):\n";
        cout << "Result: " << result << "\n";
        cout << "Time: " << elapsed.count() << " nanoseconds\n\n";
    }

    return 0;
}