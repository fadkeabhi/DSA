#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
        return;
        // find the increasing sequence from last
        int maxi = nums.size() - 1;
        for (int i = maxi; i > 0; i--)
        {
            if(nums[i-1] >= nums[i]) {maxi = i-1;}
            else break;
        }

        // find a number greater than [maxi]-1 and smaller than [maxi]
        int mini = maxi;
        for(int i=mini; i<nums.size(); i++){
            if(nums[i] > nums[maxi-1] && nums[i] < nums[maxi]){
                mini = i;
            } 
        }

        // swap maxi pos and its before
        if(maxi != 0) swap(nums[mini], nums[maxi-1]);
        
        // sort all from maxi to end
        sort(nums.begin() + maxi, nums.end());
    }
};

int main()
{
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {3, 2, 1},
        {1, 1, 5},
        {1, 3, 2}};
    Solution s;
    for (auto &testCase : testCases)
    {
        s.nextPermutation(testCase);
        for (int num : testCase)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}