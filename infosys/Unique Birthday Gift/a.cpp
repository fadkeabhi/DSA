#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10000;

class Solution {
public:
    void f(int n, int k, int prev,long long  int & ans){
        if(k==0 && prev<=n) {
            // ans = (ans + 1)%MOD;
            ans++;
            return;
        }
        if(k == 0 || prev > n) return;

        for(int i=prev; i<=n; i++){
            f(n, k-1, prev * i, ans);
        }
    }

    long long int uniqueArrays(int n, int k) {
        long long int ans = 0;
        for(int i=1; i<=n; i++){
            f(n+1, k-1, i, ans);
        }
        return ans;
    }
};

int main() {
    vector<pair<int, int>> testCases = {
        {2, 1},
        {2, 2},
        {3, 2},
        {4, 3},
    };
    Solution sol;
    for (auto& testCase : testCases) {
        cout << sol.uniqueArrays(testCase.first, testCase.second) << endl;
    }
    return 0;
}