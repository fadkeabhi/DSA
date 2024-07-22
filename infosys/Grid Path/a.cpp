#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

class Solution
{
public:

    int f(vector<vector<int>> &grid, int ind, int pos, int prev)
    {
        int n = grid.size();

        if (prev > grid[ind][pos])
            return 0;
        if (ind == n - 1)
            return grid[ind][pos];

        int l = grid[ind][pos] + f(grid, ind + 1, 0, grid[ind][pos]);

        int r = grid[ind][pos] + f(grid, ind + 1, 1, grid[ind][pos]);

        return max(l, r);
    }

    int gridPath(vector<vector<int>> &grid)
    {
        int l = f(grid, 0, 0, 0);
        int r = f(grid, 0, 1, 0);
        return max(l, r);
    }

    
};

int main()
{
    vector<vector<vector<int>>> testCases = {
        {{1, 2}, {3, 4}},
        {{7, 8}, {5, 5}},
        {{1, 1}, {2, 2}, {3, 3}}};
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.gridPath(testCase) << endl;
    }
    return 0;
}