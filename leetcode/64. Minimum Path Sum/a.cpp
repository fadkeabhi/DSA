#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
        {{1, 2, 3}, {4, 5, 6}}
    };
    Solution s;
    for (auto& testCase : testCases) {
        cout << s.minPathSum(testCase) << endl;
    }
    return 0;
}