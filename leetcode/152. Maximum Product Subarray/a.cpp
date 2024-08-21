#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(vector<int>& a){

        if(a.size() == 0) return 0;
        if(a.size() == 1) return a[0];

        // if only one negative value
        int negCount = 0;
        for(int i:a){
            if(i<0) negCount++;
        }
        if (negCount == 1) {
            int i=0;
            long p1 = 1;
            long p2 = 1;
            while(a[i] > 0){
                p1 *= a[i++];
            }
            i++;
            while(i < a.size()){
                p2 *= a[i++];
            }
            return max(p1,p2);
        }
            
        long long int prod = 1;
        for(int i:a){
            prod *= i;
        }


        if(prod>=0) return prod;
        // left neg
        long long int left_prod = 1;
        for(int i:a){
            left_prod *= i;
            if(i < 0) break;
        }

        long long int right_prod = 1;
        for(int i = a.size() -1; i>=0; i--){
            right_prod *= a[i];
            if(a[i] < 0) break;
        }
        return (int) (prod/max(left_prod, right_prod));
    }
    int maxProduct(vector<int>& nums) {
        
        vector<int> t;
        int ans = INT16_MIN;
        for(int i: nums){
            if(i == 0){
                ans = max(ans, f(t));
                ans = max(ans, 0);
                t.clear();
            } else{
                t.push_back(i);
            }
        }
        ans = max(ans, f(t));
        t.clear();
        return ans;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {2, 3, -2, 4},
        {-2, 0, -1},
        {-2, 3, -4},
        {0, 2},
        {-2},
        {0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0}
    };
    Solution s;
    for (auto& testCase : testCases) {
        cout << s.maxProduct(testCase) << endl;
    }
    return 0;
}