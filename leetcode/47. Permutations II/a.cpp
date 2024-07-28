#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void f(vector<int> nums, set<vector<int>> &ans, vector<int> &tempAns)
    {
        int n = nums.size();
        if (n == 0)
        {
            ans.insert(tempAns);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> temp(nums);
            tempAns.push_back(temp[i]);
            temp.erase(temp.begin() + i);
            f(temp, ans, tempAns);
            tempAns.erase(tempAns.end() - 1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> ans;
        vector<int> tempAns;
        f(nums, ans, tempAns);

        vector<vector<int>> finalAns;
        for (auto i : ans)
        {
            finalAns.push_back(i);
        }
        return finalAns;
    }
};

int main()
{
    vector<vector<int>> testCases = {
        {1, 1, 2},
        {1, 2, 3},
        {1, 1, 1, 2}};

    Solution s;

    for (auto &testCase : testCases)
    {
        for (auto &permutation : s.permuteUnique(testCase))
        {
            cout << "[";
            for (auto &num : permutation)
            {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }

    return 0;
}