#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int fact(int n, vector<int> &factdp)
    {
        if (factdp[n] != -1)
            return factdp[n];
        factdp[n] = fact(n - 1, factdp) * n;
        return factdp[n];
    }

    string getPermutation(int n, int k)
    {
        if(n==1) return "1";
        vector<int> factdp(n + 1, -1);
        factdp[0] = 0;
        factdp[1] = 1;

        // cout<<fact(5, factdp);
        vector<int> ans;
        vector<int> remaining;

        for (int i = 1; i <= n; i++)
            remaining.push_back(i);

        while (remaining.size() > 2)
        {
            int pos = 0;
            while (k - fact(remaining.size() - 1, factdp) > 0)
            {
                pos++;
                k = k - fact(remaining.size() - 1, factdp);
            }
            ans.push_back(remaining[pos]);
            remaining.erase(remaining.begin() + pos);
        }

        if (k == 1)
        {
            ans.push_back(remaining[0]);
            ans.push_back(remaining[1]);
        }
        else
        {
            ans.push_back(remaining[1]);
            ans.push_back(remaining[0]);
        }

        string finalAns;
        for (int i : ans)
            finalAns += to_string(i);
        

        // for (int i : remaining)
        //     cout << i << " ";
        // cout << endl;
        // for (int i : ans)
        //     cout << i << " ";

        return finalAns;
    }
};

int main()
{
    vector<pair<int, int>> testCases = {
        {3, 3}, // 213
        {4, 9}, // 2314
        {3, 1}  // 123
    };
    Solution s;
    for (auto &testCase : testCases)
    {
        cout << s.getPermutation(testCase.first, testCase.second) << endl;
    }
    return 0;
}