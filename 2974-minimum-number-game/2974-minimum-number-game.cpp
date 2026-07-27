class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i += 2) {
            ans.push_back(nums[i + 1]); 
            ans.push_back(nums[i]);     
        }

        return ans;
    }
};