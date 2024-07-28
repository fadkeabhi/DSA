#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void f(vector<int> nums, vector<vector<int>> & ans, vector<int>& tempAns){
        int n = nums.size();
        if(n == 0){
            ans.push_back(tempAns);
            return;
        }

        for(int i=0; i<n; i++){
            vector<int> temp(nums);
            tempAns.push_back(temp[i]);
            temp.erase(temp.begin() + i);
            f(temp, ans, tempAns);
            tempAns.erase(tempAns.end()-1);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tempAns;
        f(nums, ans, tempAns);
        return ans;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {0, 1},
        {1}
    };
    Solution s;
    for (auto& testCase : testCases) {
        for (auto &v: s.permute(testCase)) {
            cout << "[";
            for (auto &i: v) {
                cout << i << " ";
            }
            cout << "] ";
        }
        cout << endl;
    }
    return 0;
}