#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(vector<int>& arr, int n) {
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[1], arr[0]);
        int p2 = arr[0];
        int p1 = max(arr[0], arr[1]);
        int curr=0;

        for(int i = 2; i<n; i++){
            int pick = arr[i] + p2;
            int notpick = p1;
            curr = max(pick, notpick);
            p2 = p1;
            p1 = curr;

        }
        return p1;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        long long int withoutLast = f(nums, nums.size() - 1);
        nums.erase(nums.begin());
        long long int withoutFirst = f(nums, nums.size());
        return max(withoutLast, withoutFirst);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {2, 3, 2},
        {1, 2, 3, 1},
        {1, 2, 3},
        {0},
        {1}
    };
    Solution s;
    for (auto& testCase : testCases) {
        cout << s.rob(testCase) << endl;
    }
    return 0;
}