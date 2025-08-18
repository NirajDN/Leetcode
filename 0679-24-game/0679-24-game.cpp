class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> tmp(nums.begin(), nums.end());
        return dfs(tmp);
    }
private:
    bool dfs(vector<double>& nums){
        if(nums.size() == 1) return fabs(nums[0] - 24) < 1e-8;
        for(int i = 0; i + 1 < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                vector<double> tmp;
                for(int k = 0; k < nums.size(); ++k)
                    if(k != i && k != j) tmp.push_back(nums[k]);
                tmp.push_back(nums[i] + nums[j]);
                if(dfs(tmp)) return true;
                tmp.back() = nums[i] * nums[j];
                if(dfs(tmp)) return true;
                tmp.back() = nums[i] - nums[j];
                if(dfs(tmp)) return true;
                tmp.back() = nums[i] / nums[j];
                if(dfs(tmp)) return true;
                tmp.back() = nums[j] - nums[i];
                if(dfs(tmp)) return true;
                tmp.back() = nums[j] / nums[i];
                if(dfs(tmp)) return true;
            }
        }
        return false;
    }
};