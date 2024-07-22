#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int n){
        if (n == 0) return nums[0];
        if(n == 1) return max(nums[0] , nums[1]);
        int rob = nums[n] + f(nums, n-2);
        int notrob = f(nums, n-1);
        return max(rob, notrob);
    }

    int rob(vector<int>& nums) {
        int n =  nums.size();
        return f(nums, n -1 );
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
        {1, 3, 1, 3, 100},
        {1,2,3,1},
        {2,7,9,3,1}
    };
    Solution s;
    for (auto& testCase : testCases) {
        cout << s.rob(testCase) << endl;
    }
    return 0;
}