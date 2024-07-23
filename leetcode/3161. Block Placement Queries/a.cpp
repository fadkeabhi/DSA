#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

    void addToObs( map<int,int> & obs, int x){
        // direct insert
        if(obs.size() == 0){
            obs.insert(make_pair(x,x));
            return;
        } 
        obs.insert(make_pair(x,-1));
        auto pos = obs.find(x);

        // if first element adjust its value
        if(pos == obs.begin()){
            obs[x] = x;
        } else{
            auto back = --pos;
            pos++;
            pos->second = pos->first - back->first;
        }

        // adjust value of next element
        auto next = ++pos;
        --pos;
        if(next != obs.end()){
            next->second = next->first - pos->first;
        }
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        map<int,int> obs;
        int ansCount = 0;
        for(int i=0; i<queries.size(); i++){
            if(ansCount > ans.size()) ans.pop_back();
            // type 1,
            if(queries[i][0] == 1){
                int x = queries[i][1];
                addToObs(obs, x);
            } else{
                bool isPlaced = false;
                // handle the placement
                int x = queries[i][1];
                int l = queries[i][2];

                if(l>x){
                    ans.push_back(false);
                    ansCount++;
                    continue;
                }

                if(obs.size() == 0){
                    // direct place and continue
                    ans.push_back(true);
                    ansCount++;
                    isPlaced = true;
                    continue;
                }

                // check if after last
                auto it = obs.end();
                --it;
                if(it->first < x){
                    if(l <= x - it->first){
                        ans.push_back(true);
                        ansCount++;
                        isPlaced = true;
                        continue;
                    }
                }

                for (auto it = obs.begin(); it != obs.end(); it++) {
                    int key = it->first;
                    int value = it->second;
                    if(x>=key){
                        if(l<=value){
                            ans.push_back(true);
                            ansCount++;
                            isPlaced = true;
                            break;
                        }
                    }
                    else{
                        // handle if x < key
                        if(l<=value-(key-x)){
                            ans.push_back(true);
                            ansCount++;
                            isPlaced = true;
                            continue;
                        }
                    }
                }
                if(isPlaced == false) {
                    ansCount++;
                    ans.push_back(false);
                }
            }


        }
        for (auto it = obs.begin(); it != obs.end(); it++) {
            int key = it->first;
            int value = it->second;
            std::cout << "Key: " << key << ", Value: " << value << std::endl;
        }
        return ans;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}},
        {{1, 7}, {2, 7, 6}, {1, 2}, {2, 7, 5}, {2, 7, 6}},
        {{2,1,2}},
        {{1,1},{2,4,3}},
        {{1,4},{1,7},{2,6,1}}
    };
    Solution s;
    for (auto& testCase : testCases) {
        auto results = s.getResults(testCase);
        for (auto result : results) {
            cout << (result ? "true" : "false") << " ";
        }
        cout << endl;
    }
    return 0;
}