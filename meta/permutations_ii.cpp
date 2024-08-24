//
// Created by 62339 on 2023/10/31.
//
#include <vector>
#include <functional>
#include <unordered_map>
#include <valarray>

class permutations_ii {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::unordered_map<int,int>mp;
        for (auto x:nums){
            mp[x]++;
        }
        int n=nums.size();
        std::vector<int> res;
        std::function<void(int)> dfs=[&](int u){
            if (u==n){
                ans.push_back(res);
                return ;
            }
            for (auto &x:mp){
                if (x.second==0) continue;
                x.second--;
                res.push_back(x.first);
                dfs(u+1);
                x.second++;
                res.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};